/************************************************************\
Filename:   rail_fence_1_test.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Unit tests for Rail fence cipher

\************************************************************/


/* ===== Includes ===== */
#include <climits>
#include <gtest/gtest.h>
#include "rail_fence_cipher.hpp"

using cipher::EncryptRailFenceAlpha;
using cipher::DecryptRailFenceAlpha;


/* ===== Tests ===== */

// Identity test
TEST(RailFence, Identity1)
{
    const std::string plaintext("HELLOWORLD");
    std::string ciphertext;
    EncryptRailFenceAlpha(1, plaintext, ciphertext);
    EXPECT_EQ(plaintext, ciphertext);
}

// Test the Flee At Once message with 1 rail (identity)
TEST(RailFence, FleeAtOnce1)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WEAREDISCOVEREDFLEEATONCE");
    std::string ciphertext;

    // Encrypt with 1 rail (identity)
    EncryptRailFenceAlpha(1, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

// Test the Flee At Once message with 2 rails
TEST(RailFence, FleeAtOnce2)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WAEICVRDLETNEERDSOEEFEAOC");
    std::string ciphertext;

    // Encrypt with 2 rails
    EncryptRailFenceAlpha(2, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

// Test the Flee At Once message with 3 rails
TEST(RailFence, FleeAtOnce3)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WECRLTEERDSOEEFEAOCAIVDEN");
    std::string ciphertext;

    // Encrypt with 3 rails
    EncryptRailFenceAlpha(3, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

// Test with Flee At Once message with 4 rails
TEST(RailFence, FleeAtOnce4)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WIREEEDSEEEACAECVDLTNROFO");
    std::string ciphertext;

    // Encrypt with 4 rails
    EncryptRailFenceAlpha(4, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

// Test with Flee At Once message with 5 rails
TEST(RailFence, FleeAtOnce5)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WCLEESOFECAIVDENRDEEAOERT");
    std::string ciphertext;

    // Encrypt with 5 rails
    EncryptRailFenceAlpha(5, plaintext, ciphertext);
    EXPECT_EQ(ciphertext, ciphercheck);
}

// Test the Flee At Once message with 1 rail (identity)
TEST(RailFence, FleeAtOnceDecrypt1)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WEAREDISCOVEREDFLEEATONCE");
    std::string ciphertext;

    // Decrypt with 1 rail (identity)
    DecryptRailFenceAlpha(1, ciphercheck, ciphertext);
    EXPECT_EQ(ciphertext, plaintext);
}

// Test the Flee At Once message with 2 rails
TEST(RailFence, FleeAtOnceDecrypt2)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WAEICVRDLETNEERDSOEEFEAOC");
    std::string ciphertext;

    // Decrypt with 2 rails
    DecryptRailFenceAlpha(2, ciphercheck, ciphertext);
    EXPECT_EQ(ciphertext, plaintext);
}

// Test the Flee At Once message with 3 rails
TEST(RailFence, FleeAtOnceDecrypt3)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WECRLTEERDSOEEFEAOCAIVDEN");
    std::string ciphertext;

    // Decrypt with 3 rails
    DecryptRailFenceAlpha(3, ciphercheck, ciphertext);
    EXPECT_EQ(ciphertext, plaintext);
}

// Test with Flee At Once message with 4 rails
TEST(RailFence, FleeAtOnceDecrypt4)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WIREEEDSEEEACAECVDLTNROFO");
    std::string ciphertext;

    // Decrypt with 4 rails
    DecryptRailFenceAlpha(4, ciphercheck, ciphertext);
    EXPECT_EQ(ciphertext, plaintext);
}

// Test with Flee At Once message with 5 rails
TEST(RailFence, FleeAtOnceDecrypt5)
{
    const std::string plaintext("WEAREDISCOVEREDFLEEATONCE");
    const std::string ciphercheck("WCLEESOFECAIVDENRDEEAOERT");
    std::string ciphertext;

    // Decrypt with 5 rails
    DecryptRailFenceAlpha(5, ciphercheck, ciphertext);
    EXPECT_EQ(ciphertext, plaintext);
}

