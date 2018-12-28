/************************************************************\
Filename:   scytale_cipher.hpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This header contains definitions for using the scytale
    cipher. A scytale cipher is a transpositional cipher
    which rearranges the letters of a horizontal message
    into vertical columns.

    For this cipher, the cipher key is the width of the rows
    of text. This determines how many rows and columns form
    the square of text, which then dictates how the letters
    are transposed.

    Example: Key is 5

    Original text: Good morning world and all who inhabit it
    Plaintext: GOODMORNINGWORLDANDALLWHOINHABITIT

    Split into rows of width 5:
        1 2 3 4 5
        G O O D M
        O R N I N
        G W O R L
        D A N D A
        L L W H O
        I N H A B
        I T I T

    Read down each column, going from top to bottom:

        1. GOGDLII
        2. ORWALNT
        3. ONONWHI
        4. DIRDHAT
        5. MNLAOB

    Final ciphertext: GOGDLIIORWALNTONONWHIDIRDHATMNLAOB

    See https://en.wikipedia.org/wiki/Scytale for details.


\************************************************************/


#ifndef SCYTALE_CIPHER_HPP_
#define SCYTALE_CIPHER_HPP_


/* ===== Includes ===== */
#include <string>
#include "vigenere_cipher.hpp"


namespace cipher {

    /* ===== Functions ===== */

    /**
     * Encrypt the given plaintext using a scytale cipher
     * This function is limited to upper-case alphabet characters (A-Z)
     * @param[in]   row_width - The width of the rows of text
     * @param[in]   plaintext - The text to encrypt
     * @param[out]  ciphertext - The resulting encrypted text
     * @throw   If plaintext contains non-alpha characters
     */
    inline void EncryptScytaleAlpha(const size_t row_width, const std::string& plaintext, std::string& ciphertext)
    {
        // Allocate space for the ciphertext
        const size_t plaintext_size = plaintext.size();
        ciphertext.resize(plaintext.size());

        // Go column by column copying letters
        size_t cipher_index = 0;
        for (size_t column = 0; column < row_width; ++column)
        {
            for (size_t plain_index = column; plain_index < plaintext_size; plain_index += row_width)
            {
                ciphertext[cipher_index++] = plaintext[plain_index];
            }
        }
    }

    /**
     * Decrypt the given ciphertext using a scytale cipher
     * This function is limited to upper-case alphabet characters (A-Z)
     * @param[in]   row_width - The width of the rows of text, from the original encryption
     * @param[in]   ciphertext - The text to decrypt
     * @param[out]  plaintext - The resulting decrypted text
     * @throw   If plaintext contains non-alpha characters
     */
    inline void DecryptScytaleAlpha(const size_t row_width, const std::string& ciphertext, std::string& plaintext)
    {
        const size_t total_length = ciphertext.size();
        const size_t column_height = 1 + ((total_length - 1) / row_width);
        EncryptScytaleAlpha(column_height, ciphertext, plaintext);
    }

}   // end namespace cipher


#endif  // SCYTALE_CIPHER_HPP_
