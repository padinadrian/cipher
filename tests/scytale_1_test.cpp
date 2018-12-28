/************************************************************\
Filename:   scytale_1_test.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Unit tests for scytale cipher

\************************************************************/


/* ===== Includes ===== */
#include <climits>
#include <gtest/gtest.h>
#include "scytale_cipher.hpp"

using cipher::EncryptScytaleAlpha;
using cipher::DecryptScytaleAlpha;


/* ===== Tests ===== */

// Identity test - Use identity cipherkey 1
TEST(Scytale, EncryptIdentity1)
{
    const std::string plaintext("HELLOGOODBYEHELLOGOODBYE");
    std::string ciphertext;
    EncryptScytaleAlpha(1, plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
}

// Simple test encrypting with 5 columns (example from header)
TEST(Scytale, EncryptExample1Key5)
{
    const std::string plaintext("GOODMORNINGWORLDANDALLWHOINHABITIT");
    const std::string ciphercheck("GOGDLIIORWALNTONONWHIDIRDHATMNLAOB");
    std::string ciphertext;
    EncryptScytaleAlpha(5, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

// Simple test decrypting with 5 columns (example from header)
TEST(Scytale, DecryptExample1Key5)
{
    const std::string plaintext("GOODMORNINGWORLDANDALLWHOINHABITIT");
    const std::string ciphercheck("GOGDLIIORWALNTONONWHIDIRDHATMNLAOB");
    std::string ciphertext;
    DecryptScytaleAlpha(5, ciphercheck, ciphertext);
    EXPECT_EQ(ciphertext, plaintext);
}

// Example from Wikipedia: https://en.wikipedia.org/wiki/Scytale
TEST(Scytale, EncryptHurtVeryBadly)
{
    const std::string plaintext("Iamhurtverybadlyhelp");
    const std::string ciphercheck("Iryyatbhmvaehedlurlp");
    std::string ciphertext;
    EncryptScytaleAlpha(5, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

// Example from Wikipedia: https://en.wikipedia.org/wiki/Scytale
TEST(Scytale, DecryptHurtVeryBadly)
{
    const std::string plaintext("Iamhurtverybadlyhelp");
    const std::string ciphercheck("Iryyatbhmvaehedlurlp");
    std::string ciphertext;
    DecryptScytaleAlpha(5, ciphercheck, ciphertext);
    EXPECT_EQ(ciphertext, plaintext);
}
