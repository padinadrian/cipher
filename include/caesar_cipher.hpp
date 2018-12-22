/************************************************************\
Filename:   caesar_cipher.hpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This header contains definitions for using the Caesar
    cipher. A Caesar cipher is a simple cipher that changes
    each character in the plaintext to a different letter
    using a fixed offset. For example, if the offset is 1,
    each letter in the text is shifted to the next letter
    in the alphabet. So A becomes B, B becomes C and so on.

    In this implementation, the offset is given by the letter
    which corresponds to the number of the offset, starting
    at zero:
        A = 0, B = 1, C = 2, etc.

    Example:
    - plaintext:  HELLOWORLD
    - password:   B
    - ciphertext: IFMMPXPSME

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
     * This function is limited to upper-case alphabet characters (A-Z)
     * See https://en.wikipedia.org/wiki/Caesar_cipher for details
     * @param[in]   password - The encryption key. Use the same key to decrypt
     * @param[in]   plaintext - The text to encrypt
     * @param[out]  ciphertext - The resulting encrypted text
     * @throw   If password or plaintext contain non-alpha characters
     */
    inline void EncryptCaesarAlpha(const char password, const std::string& plaintext, std::string& ciphertext)
    {
        EncryptVigenereAlpha(std::string(1, password), plaintext, ciphertext);
    }

    /**
     * Decrypt the given ciphertext using a Caesar cipher
     * This function is limited to upper-case alphabet characters (A-Z)
     * See https://en.wikipedia.org/wiki/Caesar_cipher for details
     * @param[in]   password - The decryption key. Use the same key to encrypt
     * @param[in]   ciphertext - The text to decrypt
     * @param[out]  plaintext - The resulting decrypted text
     * @throw   If password or plaintext contain non-alpha characters
     */
    inline void DecryptCaesarAlpha(const char password, const std::string& plaintext, std::string& ciphertext)
    {
        DecryptVigenereAlpha(std::string(1, password), plaintext, ciphertext);
    }

}   // end namespace cipher


#endif  // CAESAR_CIPHER_HPP_
