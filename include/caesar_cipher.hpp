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

/* ===== Includes ===== */
#include <string>
#include "vigenere_cipher.hpp"


/* ===== Functions ===== */

inline void EncryptCaeserAlpha(const char password, const std::string& plaintext, std::string& ciphertext)
{
    EncryptVigenereAlpha(std::string(1, password + 'A'), plaintext, ciphertext);
}



