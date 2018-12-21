/************************************************************\
Filename:   caesar_1_test.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Unit tests for Caesar cipher

\************************************************************/


/* ===== Includes ===== */
#include <climits>
#include <gtest/gtest.h>
#include "caesar_cipher.hpp"

using cipher::EncryptCaesarAlpha;


/* ===== Tests ===== */

TEST(Caesar, Identity1)
{
    const std::string plaintext("HELLOWORLD");
    std::string ciphertext;
    EncryptCaesarAlpha('A', plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
}

