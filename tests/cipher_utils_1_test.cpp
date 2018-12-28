/************************************************************\
Filename:   viegenere_1_test.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Unit tests for cipher utilities

\************************************************************/


/* ===== Includes ===== */
#include <climits>
#include <gtest/gtest.h>
#include "cipher_utils.hpp"

using cipher::IsUpperAlpha;
using cipher::InvertCipherkey;


/* ===== Tests ===== */

// Check that upper-case letters pass
TEST(CipherUtils, IsUpperAlphaPass)
{
    EXPECT_TRUE(IsUpperAlpha('A'));
    EXPECT_TRUE(IsUpperAlpha('B'));
    EXPECT_TRUE(IsUpperAlpha('C'));
    EXPECT_TRUE(IsUpperAlpha('D'));
    EXPECT_TRUE(IsUpperAlpha('E'));
    EXPECT_TRUE(IsUpperAlpha('F'));
    EXPECT_TRUE(IsUpperAlpha('G'));
    EXPECT_TRUE(IsUpperAlpha('H'));
    EXPECT_TRUE(IsUpperAlpha('I'));
    EXPECT_TRUE(IsUpperAlpha('J'));
    EXPECT_TRUE(IsUpperAlpha('K'));
    EXPECT_TRUE(IsUpperAlpha('L'));
    EXPECT_TRUE(IsUpperAlpha('M'));
    EXPECT_TRUE(IsUpperAlpha('N'));
    EXPECT_TRUE(IsUpperAlpha('O'));
    EXPECT_TRUE(IsUpperAlpha('P'));
    EXPECT_TRUE(IsUpperAlpha('Q'));
    EXPECT_TRUE(IsUpperAlpha('R'));
    EXPECT_TRUE(IsUpperAlpha('S'));
    EXPECT_TRUE(IsUpperAlpha('T'));
    EXPECT_TRUE(IsUpperAlpha('U'));
    EXPECT_TRUE(IsUpperAlpha('V'));
    EXPECT_TRUE(IsUpperAlpha('W'));
    EXPECT_TRUE(IsUpperAlpha('X'));
    EXPECT_TRUE(IsUpperAlpha('Y'));
    EXPECT_TRUE(IsUpperAlpha('Z'));
}

// Check that numbers fail
TEST(CipherUtils, IsUpperAlphaFailNum)
{
    EXPECT_FALSE(IsUpperAlpha('0'));
    EXPECT_FALSE(IsUpperAlpha('1'));
    EXPECT_FALSE(IsUpperAlpha('2'));
    EXPECT_FALSE(IsUpperAlpha('3'));
    EXPECT_FALSE(IsUpperAlpha('4'));
    EXPECT_FALSE(IsUpperAlpha('5'));
    EXPECT_FALSE(IsUpperAlpha('6'));
    EXPECT_FALSE(IsUpperAlpha('7'));
    EXPECT_FALSE(IsUpperAlpha('8'));
    EXPECT_FALSE(IsUpperAlpha('9'));
}

// Check that 'A' inverts to itself
TEST(CipherUtils, InvertCipherkeyIdentity)
{
    EXPECT_EQ(InvertCipherkey("A"), "A");
}

// Check that single-letter cipherkeys are inverted
TEST(CipherUtils, InvertCipherkeySingleLetter)
{
    EXPECT_EQ(InvertCipherkey("B"), "Z");
    EXPECT_EQ(InvertCipherkey("C"), "Y");
    EXPECT_EQ(InvertCipherkey("D"), "X");
    EXPECT_EQ(InvertCipherkey("E"), "W");
    EXPECT_EQ(InvertCipherkey("F"), "V");
    EXPECT_EQ(InvertCipherkey("G"), "U");
    EXPECT_EQ(InvertCipherkey("H"), "T");
    EXPECT_EQ(InvertCipherkey("I"), "S");
    EXPECT_EQ(InvertCipherkey("J"), "R");
    EXPECT_EQ(InvertCipherkey("K"), "Q");
    EXPECT_EQ(InvertCipherkey("L"), "P");
    EXPECT_EQ(InvertCipherkey("M"), "O");
    EXPECT_EQ(InvertCipherkey("N"), "N");
    EXPECT_EQ(InvertCipherkey("O"), "M");
    EXPECT_EQ(InvertCipherkey("P"), "L");
    EXPECT_EQ(InvertCipherkey("Q"), "K");
    EXPECT_EQ(InvertCipherkey("R"), "J");
    EXPECT_EQ(InvertCipherkey("S"), "I");
    EXPECT_EQ(InvertCipherkey("T"), "H");
    EXPECT_EQ(InvertCipherkey("U"), "G");
    EXPECT_EQ(InvertCipherkey("V"), "F");
    EXPECT_EQ(InvertCipherkey("W"), "E");
    EXPECT_EQ(InvertCipherkey("X"), "D");
    EXPECT_EQ(InvertCipherkey("Y"), "C");
    EXPECT_EQ(InvertCipherkey("Z"), "B");
}

// Check several longer cipherkeys
TEST(CipherUtils, InvertCipherkeyHello)
{
    EXPECT_EQ(InvertCipherkey("HELLO"), "TWPPM");
    EXPECT_EQ(InvertCipherkey("WORLD"), "EMJPX");
}

