/************************************************************\
Filename:   cipher_utils.hpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Useful utility programs for all ciphers

\************************************************************/


/**
 * Check if a given character is a valid upper-case alphabet character
 */
inline bool IsUpperAlpha(char alpha)
{
    return ((alpha >= 'A') && (alpha <= 'Z'));
}

/**
 * Check if a given character is a valid upper-case alphabet character
 */
inline bool IsLowerAlpha(char alpha)
{
    return ((alpha >= 'a') && (alpha <= 'z'));
}
