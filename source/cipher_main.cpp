/************************************************************\
Filename:   cipher.cpp
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
#include "vigenere_cipher.hpp"
#include "caesar_cipher.hpp"
#include "cipher_usage.hpp"

using cipher::EncryptCaesarAlpha;
using cipher::EncryptVigenereAlpha;


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
                             std::string& password,
                             std::istream& input_file,
                             std::ostream& output_file)
{
    // End result return code
    int32_t retval = 0;

    // Input
    std::string plaintext;
    ReadFromFile(input_file, plaintext);
    (void)cipher::rtrim(plaintext);
    (void)cipher::rtrim(password);

    // Do the cipher
    std::string ciphertext;
    if (method == "vigenere")
    {
        try
        {
            EncryptVigenereAlpha(password, plaintext, ciphertext);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            retval = 1;
        }
    }
    else if (method == "caesar")
    {
        try
        {
            EncryptCaesarAlpha(password[0], plaintext, ciphertext);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            retval = 1;
        }
    }
    else
    {
        std::cerr << "Error: method \"" << method << "\" not supported." << std::endl;
        retval = 1;
    }

    // Output
    output_file << ciphertext << std::endl;
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
    std::string password;
    while ((opt = getopt(argc, argv, ":m:p:")) != -1)
    {
        switch(opt)
        {
            // m for METHOD
            case 'm':
            {
                method = optarg;
                break;
            }
            // p for PASSWORD
            case 'p':
            {
                password = optarg;
                break;
            }
            // Option missing a value
            case ':':
            {
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

    // Check for errors in arguments
    if (method.empty())
    {
        std::cerr << "Error: No method given." << std::endl;
        retval = 1;
    }
    if (password.empty())
    {
        std::cerr << "Error: No password given." << std::endl;
        retval = 1;
    }

    if (retval != 0)
    {
        std::cout << usage_str << std::endl;
    }
    else
    {
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
            retval = ExecuteCipher(method, password, std::cin, std::cout);
        }
        // Use stdin for input and file for output
        else if (use_stdin)
        {
            std::ofstream outfile(argv[optind + 1]);
            retval = ExecuteCipher(method, password, std::cin, outfile);
        }
        // Use file for input and stdout for output
        else if (use_stdout)
        {
            std::ifstream infile(argv[optind]);
            retval = ExecuteCipher(method, password, infile, std::cout);
        }
        // Use files for input and output
        else
        {
            std::ifstream infile(argv[optind]);
            std::ofstream outfile(argv[optind + 1]);
            retval = ExecuteCipher(method, password, infile, outfile);
        }
    }

    return retval;
}



