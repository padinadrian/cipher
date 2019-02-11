/************************************************************\
Filename:   columnar_1_test.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Unit tests for Columnar cipher

\************************************************************/


/* ===== Includes ===== */
#include <climits>
#include <gtest/gtest.h>
#include "columnar_cipher.hpp"

using cipher::EncryptColumnarAlpha;


/* ===== Tests ===== */

TEST(Columnar, ZebraWikipediaTest)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCEQKJEU");
    const std::string ciphercheck("EVLNEACDTKESEAQROFOJDEECUWIREE");
    std::string ciphertext;
    EncryptColumnarAlpha("ZEBRAS", plaintext, ciphertext);
    EXPECT_EQ(ciphercheck, ciphertext);
}

