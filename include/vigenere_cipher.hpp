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
     * This funciton is limited to upper-case alphabet characters (A-Z)
     * See https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher for details
     * @param[in]   password - The encryption keyword. Use the same keyword to decrypt
     * @param[in]   plaintext - The text to encrypt
     * @param[out]  ciphertext - The resulting encrypted text
     * @throw   If password or plaintext contain non-alpha characters
     */
    inline void EncryptVigenereAlpha(const std::string& password, const std::string& plaintext, std::string& ciphertext)
    {
        // Cipher text should be same length as plaintext
        ciphertext.resize(plaintext.size());

        auto password_iter = password.cbegin();
        const auto password_end = password.cend();
        auto plaintext_iter = plaintext.cbegin();
        const auto plaintext_end = plaintext.cend();
        auto ciphertext_iter = ciphertext.begin();

        while (plaintext_iter != plaintext_end)
        {
            if (IsUpperAlpha(*password_iter))
            {
                if (IsUpperAlpha(*plaintext_iter))
                {
                    const char offset1 = (*password_iter) - 'A';
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
                    << PrintCharHex(*password_iter)
                    << " found in password";
                throw std::runtime_error(oss.str());
            }
            password_iter++;
            plaintext_iter++;
            ciphertext_iter++;

            if (password_iter == password_end) {
                password_iter = password.cbegin();
            }
        }
    }

}   // end namespace cipher


#endif  // VIGENERE_CIPHER_HPP_
