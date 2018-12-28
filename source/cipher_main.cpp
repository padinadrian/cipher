/************************************************************\
Filename:   cipher_main.cpp
Author:     Adrian Padin (padin.adrian@gmail.com)
Description:
    This is the starter file for the cipher program
    This program can be used to encode and decode simple
    ciphers.

    Supported ciphers:
    - Caesar cipher
    - Vigenere cipher

\************************************************************/


/* ===== Includes ===== */
#include <cstdio>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include "unistd.h"
#include "cipher_usage.hpp"
#include "cipher_version.hpp"
#include "caesar_cipher.hpp"
#include "vigenere_cipher.hpp"
#include "rail_fence_cipher.hpp"
#include "scytale_cipher.hpp"

using cipher::EncryptCaesarAlpha;
using cipher::DecryptCaesarAlpha;
using cipher::EncryptVigenereAlpha;
using cipher::DecryptVigenereAlpha;
using cipher::EncryptRailFenceAlpha;
using cipher::DecryptRailFenceAlpha;
using cipher::EncryptScytaleAlpha;
using cipher::DecryptScytaleAlpha;
using cipher::VERSION_FULL;


/**
 * Cipher method to use
 */
enum EncryptMethod
{
    ENCRYPT_METHOD_CAESAR_ALPHA,
    ENCRYPT_METHOD_VIGENERE_ALPHA,
};


/* ===== Functions ===== */

/**
 * Read data from the file into string
 * If the file is empty or can't be opened, empty string is returned
 */
static void ReadFromFile(const std::istream& input_file, std::string& output_str)
{
    std::stringstream buffer;
    buffer << input_file.rdbuf();
    output_str = buffer.str();
}

/**
 *
 */
static int32_t ExecuteCipher(const std::string& method,
                             std::string& cipherkey,
                             std::istream& input_file,
                             std::ostream& output_file,
                             bool decrypt_flag)
{
    // End result return code
    int32_t retval = 0;

    // Input checking
    if (!output_file)
    {
        std::cerr << "Error: output file could not be opened" << std::endl;
        retval = 1;
    }
    else if (!input_file)
    {
        std::cerr << "Error: input file could not be opened" << std::endl;
        retval = 1;
    }
    else
    {
        try
        {
            // Input
            std::string plaintext;
            ReadFromFile(input_file, plaintext);
            (void)cipher::rtrim(plaintext);
            (void)cipher::rtrim(cipherkey);

            // Do the cipher
            std::string ciphertext;
            if (method == "vigenere")
            {
                if (decrypt_flag)
                {
                    DecryptVigenereAlpha(cipherkey, plaintext, ciphertext);
                }
                else
                {
                    EncryptVigenereAlpha(cipherkey, plaintext, ciphertext);
                }
            }
            else if (method == "caesar")
            {
                if (decrypt_flag)
                {
                    DecryptCaesarAlpha(cipherkey[0], plaintext, ciphertext);
                }
                else
                {
                    EncryptCaesarAlpha(cipherkey[0], plaintext, ciphertext);
                }
            }
            else if (method == "railfence")
            {
                // Determine the correct key
                // In this case, the number of rails
                size_t num_rails = 0U;
                char num_rails_char = cipherkey[0];
                if ((num_rails_char > '0') && (num_rails_char <= '9'))
                {
                    num_rails = static_cast<size_t>(num_rails_char - '0');
                }
                else
                {
                    throw std::runtime_error(std::string("Bad key \"") + cipherkey + "\"; key for rail fence cipher is a number 0-9.");
                }

                if (decrypt_flag)
                {
                    DecryptRailFenceAlpha(num_rails, plaintext, ciphertext);
                }
                else
                {
                    EncryptRailFenceAlpha(num_rails, plaintext, ciphertext);
                }
            }
            else if (method == "scytale")
            {
                // Determine the correct key
                // In this case, the width of the rows
                size_t row_width = 0U;
                char row_width_char = cipherkey[0];
                if ((row_width_char > '0') && (row_width_char <= '9'))
                {
                    row_width = static_cast<size_t>(row_width_char - '0');
                }
                else
                {
                    throw std::runtime_error(std::string("Bad key \"") + cipherkey + "\"; key for scytale cipher is a number 0-9.");
                }

                if (decrypt_flag)
                {
                    DecryptScytaleAlpha(row_width, plaintext, ciphertext);
                }
                else
                {
                    EncryptScytaleAlpha(row_width, plaintext, ciphertext);
                }

            }
            else
            {
                std::cerr << "Error: method \"" << method << "\" not supported." << std::endl;
                retval = 1;
            }

            // Output
            output_file << ciphertext << std::endl;
        }
        // Catch any exceptions from running the cipher
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            retval = 1;
        }
    }
    return retval;
}


/* ===== MAIN ===== */

int main(int32_t argc, char* const* argv)
{
    // Final result
    int32_t retval = 0;

    // Process arguments
    int32_t opt = 0;
    std::string method;
    std::string cipherkey;
    bool decrypt_flag = false;
    while ((opt = getopt(argc, argv, ":hvdm:k:")) != -1)
    {
        switch(opt)
        {
            // h is for help
            case 'h':
            {
                // Print help information and exit
                std::cout << usage_str;
                retval = 1;
                break;
            }
            // v is for version
            case 'v':
            {
                // Print version information and exit
                std::cout << "cipher: " << VERSION_FULL << std::endl;
                std::cout << "Copyright (C) 2018 Adrian Padin <padin.adrian@gmail.com>" << std::endl;
                std::cout << "Software released under MIT License, provided free and without warranty" << std::endl;
                std::cout << "View source at https://github.com/padinadrian/cipher" << std::endl;
                retval = 1;
                break;
            }
            // m for METHOD
            case 'm':
            {
                method = optarg;
                break;
            }
            // k for CIPHERKEY
            case 'k':
            {
                cipherkey = optarg;
                break;
            }
            // d means decode/decrypt
            case 'd':
            {
                decrypt_flag = true;
                break;
            }
            // Option missing a value
            case ':':
            {
                std::cerr << "Error: Option missing a value." << std::endl;
                std::cerr << "Try 'cipher -h' for more information." << std::endl;
                retval = 1;
                break;
            }
            // Unknown option
            case '?':
            {
                retval = 1;
                break;
            }
        }
    }

    if (retval == 0)
    {
        // Check for errors in arguments
        if (method.empty())
        {
            std::cerr << "Error: No method given." << std::endl;
            retval = 1;
        }
        if (cipherkey.empty())
        {
            std::cerr << "Error: No cipherkey given." << std::endl;
            retval = 1;
        }
        if (cipherkey.empty() || method.empty())
        {
            std::cerr << "Try 'cipher -h' for more information." << std::endl;
        }
        else {

            // Figure out input/output arguments
            bool use_stdin = false;
            bool use_stdout = false;
            switch(argc - optind)
            {
                // If optind == argc there are no arguments
                // Use stdin and stdout
                case 0:
                {
                    use_stdin = true;
                    use_stdout = true;
                    break;
                }
                // If there is one argument, use as input file
                // Use input from file and output to stdout
                case 1:
                {
                    use_stdin = (argv[optind][0] == '-');
                    use_stdout = true;
                    break;
                }
                // If there are two arguments, use files as input and output
                case 2:
                default:    // ignore other arguments
                {
                    use_stdin = (argv[optind][0] == '-');
                    use_stdout = (argv[optind + 1][0] == '-');
                    break;
                }
            }

            // Use both stdin and stdout
            if (use_stdin && use_stdout)
            {
                retval = ExecuteCipher(method, cipherkey, std::cin, std::cout, decrypt_flag);
            }
            // Use stdin for input and file for output
            else if (use_stdin)
            {
                std::ofstream outfile(argv[optind + 1]);
                retval = ExecuteCipher(method, cipherkey, std::cin, outfile, decrypt_flag);
            }
            // Use file for input and stdout for output
            else if (use_stdout)
            {
                std::ifstream infile(argv[optind]);
                retval = ExecuteCipher(method, cipherkey, infile, std::cout, decrypt_flag);
            }
            // Use files for input and output
            else
            {
                std::ifstream infile(argv[optind]);
                std::ofstream outfile(argv[optind + 1]);
                retval = ExecuteCipher(method, cipherkey, infile, outfile, decrypt_flag);
            }
        }
    }

    return retval;
}



