/************************************************************\
Filename:   cipher_main.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This is the starter file for the cipher program
    This program can be used to encode and decode simple
    ciphers.

    Supported ciphers:
    - Caesar cipher
    - Vigenere cipher

\************************************************************/


/* ===== Includes ===== */
#include <string>
#include <algorithm>
#include <stdexcept>


namespace cipher
{
    // Helper function
    // Check if all characters in the given text are in the correct range
    // Range is [0, alphabet_size)
    static inline bool CheckPlaintextRange(
        const std::string& plaintext,
        const unsigned char max)
    {
        return std::all_of(
            plaintext.begin(),
            plaintext.end(),
            [max](const char c) { return c < max; }
        );
    }

    // Encrypt using a generalized vigenere cipher
    // Both plaintext and cipherkey must only have characters
    // in the range [0, alphabet_size)
    void EncryptVigenereGeneralized(
        const std::string& cipherkey,
        const std::string& plaintext,
        std::string& ciphertext,
        const unsigned char alphabet_size)
    {
        // Range check on plaintext
        if (!CheckPlaintextRange(plaintext, alphabet_size))
        {
            throw std::runtime_error("Character out of range in plaintext");
        }
        // Range check on cipherkey
        else if (!CheckPlaintextRange(cipherkey, alphabet_size))
        {
            throw std::runtime_error("Character out of range in cipherkey");
        }
        else
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
                // y = (x + k) % size
                // Example: using alphabet UpperAlpha
                //  x = 'B' or 1, k = 'Z' or 25, size = 26
                //  y = ('B' + 'Z') % 26 = (1 + 25) % 26 = 0 or 'A'
                *ciphertext_iter = (*plaintext_iter + *cipherkey_iter) % alphabet_size;

                // Move iterators forward
                cipherkey_iter++;
                plaintext_iter++;
                ciphertext_iter++;

                // If end of cipherkey, start back at beginning
                // Repeat until we reach end of plaintext
                if (cipherkey_iter == cipherkey_end) {
                    cipherkey_iter = cipherkey.cbegin();
                }
            }
        }
    }

    // Call the generalized Vigenere algorithm with the UpperAlpha alphabet
    // UpperAlpha is the 26 upper-case letters A -> Z
    void EncryptVigenereUpperAlpha(
        const std::string& cipherkey,
        const std::string& plaintext,
        std::string& ciphertext)
    {
        // Shift plaintext to be in range [0, 25]
        std::string shifted_plaintext(plaintext);
        std::for_each(
            shifted_plaintext.begin(),
            shifted_plaintext.end(),
            [](char& c) { c -= 'A'; }
        );

        // Shift cipherkey to be in range [0, 25]
        std::string shifted_cipherkey(cipherkey);
        std::for_each(
            shifted_cipherkey.begin(),
            shifted_cipherkey.end(),
            [](char& c) { c -= 'A'; }
        );

        // Encrypt using generalized vigenere
        const unsigned char alphabet_size = 26U;
        EncryptVigenereGeneralized(
            shifted_cipherkey, shifted_plaintext, ciphertext, alphabet_size);

        // Shift back into UpperAlpha range
        std::for_each(
            ciphertext.begin(),
            ciphertext.end(),
            [](char& c) { c += 'A'; }
        );
    }



}



#include <iostream>
int main()
{
    std::string ciphertext;
    cipher::EncryptVigenereUpperAlpha("B", "HELLOWORLD", ciphertext);
    std::cout << "result: " << ciphertext << std::endl;
    std::cout << "expected: " << "IFMMPXPSME" << std::endl;
}

