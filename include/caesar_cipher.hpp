/************************************************************\
Filename:   cipher.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This is the starter file for the cipher program
    This program can be used to encode and decode simple
    ciphers.

    Supported ciphers:
    - Caesar cipher
    - Vigenere cipher

\************************************************************/


#ifndef CAESAR_CIPHER_HPP_
#define CAESAR_CIPHER_HPP_


/* ===== Includes ===== */
#include <string>
#include "vigenere_cipher.hpp"


namespace cipher {

    /* ===== Functions ===== */

    /**
     * Encrypt the given plaintext using a Caesar cipher
     * This funciton is limited to upper-case alphabet characters (A-Z)
     * See https://en.wikipedia.org/wiki/Caesar_cipher for details
     * @param[in]   password - The encryption offset. Use the same offset to decrypt
     * @param[in]   plaintext - The text to encrypt
     * @param[out]  ciphertext - The resulting encrypted text
     * @throw   If password or plaintext contain non-alpha characters
     */
    inline void EncryptCaesarAlpha(const char password, const std::string& plaintext, std::string& ciphertext)
    {
        EncryptVigenereAlpha(std::string(1, password), plaintext, ciphertext);
    }

}   // end namespace cipher


#endif  // CAESAR_CIPHER_HPP_
