/************************************************************\
Filename:   viegenere_1_test.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Unit tests for Vigenere cipher

\************************************************************/


/* ===== Includes ===== */
#include <climits>
#include <gtest/gtest.h>
#include "vigenere_cipher.hpp"

using cipher::EncryptVigenereAlpha;


/* ===== Tests ===== */

// Identity test - Use identity password (AAA...)
// Input should be the same as output
TEST(Vigenere, Identity1)
{
    const std::string plaintext("HELLO");
    std::string ciphertext;
    EncryptVigenereAlpha("A", plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
    EncryptVigenereAlpha("AA", plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
    EncryptVigenereAlpha("AAAAA", plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
    EncryptVigenereAlpha("AAAAAAAAAA", plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
    EncryptVigenereAlpha("AAAAAAAAAAAAAAAAAAAA", plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
}

TEST(Vigenere, IdentityFox)
{
    const std::string plaintext("THEQUICKBROWNFOXJUMPEDOVERTHELAZYDOG");
    std::string ciphertext;
    EncryptVigenereAlpha("A", plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
}

// Simple one letter password
// Every letter should be shifted by one
TEST(Vigenere, SimpleB)
{
    const std::string plaintext("HELLO");
    const std::string ciphercheck("IFMMP");
    std::string ciphertext;
    EncryptVigenereAlpha("B", plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

TEST(Vigenere, SelfFox)
{
    const std::string plaintext(  "THEQUICKBROWNFOXJUMPEDOVERTHELAZYDOG");
    const std::string ciphercheck("MOIGOQEUCICSAKCUSOYEIGCQIIMOIWAYWGCM");
    std::string ciphertext;
    EncryptVigenereAlpha(plaintext, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

TEST(Vigenere, SelfFoxInPlace)
{
    std::string plaintext(  "THEQUICKBROWNFOXJUMPEDOVERTHELAZYDOG");
    const std::string ciphercheck("MOIGOQEUCICSAKCUSOYEIGCQIIMOIWAYWGCM");
    EncryptVigenereAlpha(plaintext, plaintext, plaintext);
    EXPECT_EQ(plaintext, ciphercheck);
}

