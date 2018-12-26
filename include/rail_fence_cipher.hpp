/************************************************************\
Filename:   rail_fence_cipher.hpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This header contains definitions for using the Rail fence
    cipher.

    See https://en.wikipedia.org/wiki/Rail_fence_cipher

\************************************************************/


#ifndef RAIL_FENCE_CIPHER_HPP_
#define RAIL_FENCE_CIPHER_HPP_


/* ===== Includes ===== */
#include <string>
#include <exception>
#include "cipher_utils.hpp"


namespace cipher {

    /* ===== Functions ===== */

    /**
     * Encrypt the given plaintext using a Rail fence cipher
     * This function is limited to upper-case alphabet characters (A-Z)
     * @param[in]   num_rails - The encryption key, number of rails used for encryption.
     *                          Use the same key to decrypt.
     * @param[in]   plaintext - The text to encrypt
     * @param[out]  ciphertext - The resulting encrypted text
     * @throw   If password or plaintext contain non-alpha characters
     */
    inline void EncryptRailFenceAlpha(const size_t num_rails, const std::string& plaintext, std::string& ciphertext)
    {
        // Input checking
        if (!AllUpperAlpha(plaintext))
        {
            throw std::runtime_error("Error: non-alpha character in plaintext.");
        }
        else if (num_rails <= 0)
        {
            throw std::runtime_error("Error: number of rails must be > 0");
        }
        else if (num_rails == 1)
        {
            ciphertext = plaintext; // identity, plaintext is unchanged
        }
        else
        {
            // Allocate space for the ciphertext
            const size_t plaintext_size = plaintext.size();
            ciphertext.resize(plaintext_size);
            size_t ciphertext_index = 0U;
            for (size_t rail_n = 0; rail_n < num_rails; ++rail_n)
            {
                // gap1 = (num_rails - rail_n - 1) * 2
                const size_t gap1 = (num_rails - rail_n - 1) << 1;  // same as x2
                const size_t gap2 = ((num_rails - 1) << 1) - gap1;

                // Starting point, rail_n
                size_t plaintext_index = rail_n;
                size_t gap = 1;
                bool gap_switch = true;
                while (plaintext_index < plaintext_size)
                {
                    if (gap > 0)
                    {
                        ciphertext[ciphertext_index++] = plaintext[plaintext_index];
                    }
                    gap = (gap_switch ? gap1 : gap2);
                    gap_switch = !gap_switch;
                    plaintext_index += gap;
                }
            }
        }
    }

    /**
     * Decrypt the given ciphertext using a Rail fence cipher
     * This function is limited to upper-case alphabet characters (A-Z)
     * @param[in]   num_rails - The encryption key, number of rails used for decryption.
     *                          Use the same key to encrypt.
     * @param[in]   ciphertext - The text to decrypt
     * @param[out]  plaintext - The resulting decrypted text
     * @throw   If password or plaintext contain non-alpha characters
     */
    inline void DecryptRailFenceAlpha(const size_t num_rails, const std::string& ciphertext, std::string& plaintext)
    {
        // Input checking
        if (!AllUpperAlpha(ciphertext))
        {
            throw std::runtime_error("Error: non-alpha character in plaintext.");
        }
        else if (num_rails <= 0)
        {
            throw std::runtime_error("Error: number of rails must be > 0");
        }
        else if (num_rails == 1)
        {
            plaintext = ciphertext; // identity, ciphertext is unchanged
        }
        else
        {
            // Allocate space for the plaintext
            const size_t plaintext_size = ciphertext.size();
            plaintext.resize(plaintext_size);
            size_t ciphertext_index = 0U;
            for (size_t rail_n = 0; rail_n < num_rails; ++rail_n)
            {
                // gap1 = (num_rails - rail_n - 1) * 2
                const size_t gap1 = (num_rails - rail_n - 1) << 1;  // same as x2
                const size_t gap2 = ((num_rails - 1) << 1) - gap1;

                // Starting point, rail_n
                size_t plaintext_index = rail_n;
                size_t gap = 1;
                bool gap_switch = true;
                while (plaintext_index < plaintext_size)
                {
                    if (gap > 0)
                    {
                        plaintext[plaintext_index] = ciphertext[ciphertext_index++];
                    }
                    gap = (gap_switch ? gap1 : gap2);
                    gap_switch = !gap_switch;
                    plaintext_index += gap;
                }
            }
        }
    }

}   // end namespace cipher


#endif  // RAIL_FENCE_CIPHER_HPP_
