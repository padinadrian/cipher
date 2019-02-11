/************************************************************\
Filename:   caesar_cipher.hpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This header contains definitions for using the Columnar
    cipher. The Columnar is similar to a scytale cipher,
    where the plaintext is wrapped in columns and the cipher
    text is read down, transposing the data. The difference
    is that the columns are not read in order from left to
    right - instead, they are read in the order given by a
    cipher key which gives both the number of columns and
    the order in which they are rearranged.

    Example:
    - plaintext:  We are discovered. Flee at once
    - cipherkey:  ZEBRAS

    Make all uppercase
    Remove punctuation/whitespace
    Add extra letters
    (Need length to be multiple of length of key == 6)
    - parsed text: WEAREDISCOVEREDFLEEATONCEQKJEU

    Number of columns = len(ZEBRAS) = 6
    Order of columns =  6 3 2 4 1 5

        6 3 2 4 1 5         1. EVLNE
        W E A R E D         2. ACDTK
        I S C O V E         3. ESEAQ
        R E D F L E         4. ROFOJ
        E A T O N C         5. DEECU
        E Q K J E U         6. WIREE

    - ciphertext: EVLNEACDTKESEAQROFOJDEECUWIREE

    Adapted from https://en.wikipedia.org/wiki/Transposition_cipher#Columnar_transposition

\************************************************************/


#ifndef COLUMNAR_CIPHER_HPP_
#define COLUMNAR_CIPHER_HPP_


/* ===== Includes ===== */
#include <string>
#include <random>
#include <numeric>
#include <algorithm>
#include "vigenere_cipher.hpp"


namespace cipher {

    /* ===== Helper Functions ===== */

    /**
     * Adapted from: https://stackoverflow.com/a/12399290/5179394
     */
    static inline std::vector<size_t> SortIndices(const std::string &s)
    {
        // Initialize original index locations
        std::vector<size_t> indices(s.size());
        std::iota(indices.begin(), indices.end(), 0);

        // Sort indices based on comparing values in s
        std::sort(indices.begin(), indices.end(),
            [&s](size_t i1, size_t i2) { return s[i1] < s[i2]; } );

        return indices;
    }


    /* ===== Functions ===== */

    /**
     * Encrypt the given plaintext using a Columnar cipher
     */
    void EncryptColumnarAlpha(
        const std::string& cipherkey,
        const std::string& plaintext,
        std::string& ciphertext)
    {
        const size_t num_columns = cipherkey.size();

        // Fill in extra characters (if necessary)
        std::string plaintext_copy(plaintext);
        if ((plaintext_copy.size() % num_columns) != 0)
        {
            // Distribution in upper-alpha range
            std::mt19937 rng;
            rng.seed(std::random_device()());
            std::uniform_int_distribution<char> dist_char('A', 'Z');
            while ((plaintext_copy.size() % num_columns) != 0)
            {
                plaintext_copy.push_back(dist_char(rng));
            }
        }

        // Determine column order
        ciphertext.resize(plaintext_copy.size());
        size_t cipher_index = 0;
        for (auto offset: SortIndices(cipherkey))
        {
            // starting with offset, add every Nth character
            // where N = number of columns
            for (size_t plain_index = offset;
                 plain_index < ciphertext.size();
                 plain_index += num_columns)
            {
                ciphertext[cipher_index++] = plaintext_copy[plain_index];
            }
        }
    }


}   // end namespace cipher


#endif  // COLUMNAR_CIPHER_HPP_
