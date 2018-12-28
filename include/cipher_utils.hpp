/************************************************************\
Filename:   cipher_utils.hpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    Useful utility programs for all ciphers

\************************************************************/


#ifndef CIPHER_UTILS_HPP_
#define CIPHER_UTILS_HPP_


/* ===== Includes ===== */
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <sstream>
#include <iomanip>
#include <iostream>


namespace cipher {

    /* ===== Functions ===== */

    /** Check if a given character is a valid upper-case alphabet character */
    inline bool IsUpperAlpha(const char alpha)
    {
        return ((alpha >= 'A') && (alpha <= 'Z'));
    }

    /** Check if a given character is a valid upper-case alphabet character */
    inline bool IsLowerAlpha(const char alpha)
    {
        return ((alpha >= 'a') && (alpha <= 'z'));
    }

    /** Convert a chart to a hexadecimal string */
    inline std::string PrintCharHex(const char alpha)
    {
        std::ostringstream oss;
        oss << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint32_t>(static_cast<uint8_t>(alpha));
        return oss.str();
    }

    /** Invert a cipherkey (for A-Z alphabet) so it can be used for decryption */
    inline std::string InvertCipherkey(const std::string& cipherkey)
    {
        std::string reverse_key(cipherkey);
        for (auto it = reverse_key.begin(); it != reverse_key.end(); ++it)
        {
            // y = (26 - x) % 26
            const char alphasize = static_cast<char>(26);
            const char numerical = (*it - 'A');
            *it = ((alphasize - numerical) % alphasize) + 'A';
        }
        return reverse_key;
    }

    /** Check if all letters in the plaintext are upper-case letters */
    inline bool AllUpperAlpha(const std::string& plaintext)
    {
        return std::all_of(plaintext.begin(), plaintext.end(), IsUpperAlpha);
    }


    // Whitespace trim functions
    // Taken from https://stackoverflow.com/a/217605/5179394

    /**  Trim whitespace from start */
    static inline std::string &ltrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    /** Trim whitespace from end */
    static inline std::string &rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }

    /** Trim whitespace from both ends */
    static inline std::string &trim(std::string &s)
    {
        return ltrim(rtrim(s));
    }

}   // end namespace cipher


#endif  // CIPHER_UTILS_HPP_
