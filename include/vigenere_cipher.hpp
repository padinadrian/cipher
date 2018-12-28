/************************************************************\
Filename:   vigenere_cipher.hpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This header contains definitions for using the Vigenere
    cipher. A Vigenere cipher is an extended form of the
    Caesar cipher; instead of every character being shifted
    by the same offset, each character has a different offset
    which follows a pattern determined by the cipher key.

    For example, if the cipher key is HELLO:
    * The 1st letter is shifted by 7  (for H)
    * The 2nd letter is shifted by 4  (for E)
    * The 3rd letter is shifted by 11 (for L)
    * The 4th letter is shifted by 11 (for L)
    * The 5th letter is shifted by 14 (for O)
    * The 6th letter is shifted by 7  (for H)
    * ...

    And so on for all letters in the plaintext. So, a Vigenere
    cipher operates somewhat like many independent Caesar
    ciphers.

\************************************************************/


#ifndef VIGENERE_CIPHER_HPP_
#define VIGENERE_CIPHER_HPP_


/* ===== Includes ===== */
#include <string>
#include <sstream>
#include "cipher_utils.hpp"


namespace cipher {

    /* ===== Functions ===== */

    /**
     * Encrypt the given plaintext using a Vigenere cipher
     * This function is limited to upper-case alphabet characters (A-Z)
     * See https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher for details
     * @param[in]   cipherkey - The encryption keyword. Use the same keyword to decrypt
     * @param[in]   plaintext - The text to encrypt
     * @param[out]  ciphertext - The resulting encrypted text
     * @throw   If cipherkey or plaintext contain non-alpha characters
     */
    inline void EncryptVigenereAlpha(const std::string& cipherkey, const std::string& plaintext, std::string& ciphertext)
    {
        // Cipher text should be same length as plaintext
        ciphertext.resize(plaintext.size());

        auto cipherkey_iter = cipherkey.cbegin();
        const auto cipherkey_end = cipherkey.cend();
        auto plaintext_iter = plaintext.cbegin();
        const auto plaintext_end = plaintext.cend();
        auto ciphertext_iter = ciphertext.begin();

        while (plaintext_iter != plaintext_end)
        {
            if (IsUpperAlpha(*cipherkey_iter))
            {
                if (IsUpperAlpha(*plaintext_iter))
                {
                    const char offset1 = (*cipherkey_iter) - 'A';
                    const char offset2 = (*plaintext_iter) - 'A';
                    *ciphertext_iter = ((offset1 + offset2) % 26) + 'A';
                }
                else
                {
                    std::stringstream oss;
                    oss << "Non alphabet character 0x"
                        << PrintCharHex(*plaintext_iter)
                        << " found in plaintext";
                    throw std::runtime_error(oss.str());
                }
            }
            else {
                std::stringstream oss;
                oss << "Non alphabet character 0x"
                    << PrintCharHex(*cipherkey_iter)
                    << " found in cipherkey";
                throw std::runtime_error(oss.str());
            }
            cipherkey_iter++;
            plaintext_iter++;
            ciphertext_iter++;

            if (cipherkey_iter == cipherkey_end) {
                cipherkey_iter = cipherkey.cbegin();
            }
        }
    }

    /**
     * Decrypt the given ciphertext using a Vigenere cipher
     * This function is limited to upper-case alphabet characters (A-Z)
     * See https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher for details
     * @param[in]   cipherkey - The encryption keyword. Use the same keyword to encrypt
     * @param[in]   ciphertext - The text to decrypt
     * @param[out]  plaintext - The resulting decrypted text
     * @throw   If cipherkey or ciphertext contain non-alpha characters
     */
    inline void DecryptVigenereAlpha(const std::string& cipherkey, const std::string& ciphertext, std::string& plaintext)
    {
        EncryptVigenereAlpha(InvertCipherkey(cipherkey), ciphertext, plaintext);
    }

}   // end namespace cipher


#endif  // VIGENERE_CIPHER_HPP_
