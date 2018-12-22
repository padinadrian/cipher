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
using cipher::InvertPassword;


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
TEST(CipherUtils, InvertPasswordIdentity)
{
    EXPECT_EQ(InvertPassword("A"), "A");
}

// Check that single-letter passwords are inverted
TEST(CipherUtils, InvertPasswordSingleLetter)
{
    EXPECT_EQ(InvertPassword("B"), "Z");
    EXPECT_EQ(InvertPassword("C"), "Y");
    EXPECT_EQ(InvertPassword("D"), "X");
    EXPECT_EQ(InvertPassword("E"), "W");
    EXPECT_EQ(InvertPassword("F"), "V");
    EXPECT_EQ(InvertPassword("G"), "U");
    EXPECT_EQ(InvertPassword("H"), "T");
    EXPECT_EQ(InvertPassword("I"), "S");
    EXPECT_EQ(InvertPassword("J"), "R");
    EXPECT_EQ(InvertPassword("K"), "Q");
    EXPECT_EQ(InvertPassword("L"), "P");
    EXPECT_EQ(InvertPassword("M"), "O");
    EXPECT_EQ(InvertPassword("N"), "N");
    EXPECT_EQ(InvertPassword("O"), "M");
    EXPECT_EQ(InvertPassword("P"), "L");
    EXPECT_EQ(InvertPassword("Q"), "K");
    EXPECT_EQ(InvertPassword("R"), "J");
    EXPECT_EQ(InvertPassword("S"), "I");
    EXPECT_EQ(InvertPassword("T"), "H");
    EXPECT_EQ(InvertPassword("U"), "G");
    EXPECT_EQ(InvertPassword("V"), "F");
    EXPECT_EQ(InvertPassword("W"), "E");
    EXPECT_EQ(InvertPassword("X"), "D");
    EXPECT_EQ(InvertPassword("Y"), "C");
    EXPECT_EQ(InvertPassword("Z"), "B");
}

// Check several longer passwords
TEST(CipherUtils, InvertPasswordHello)
{
    EXPECT_EQ(InvertPassword("HELLO"), "TWPPM");
    EXPECT_EQ(InvertPassword("WORLD"), "EMJPX");
}

