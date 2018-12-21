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


/* ===== Tests ===== */

//
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