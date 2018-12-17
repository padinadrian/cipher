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
#include <iostream>
#include <fstream>
#include <sstream>
#include "unistd.h"
#include "vigenere_cipher.hpp"
#include "cipher_usage.hpp"


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

    printf("method: %s\n", method.c_str());
    printf("password: %s\n", password.c_str());

    // Input
    std::string plaintext;
    ReadFromFile(input_file, plaintext);

    // Do the cipher
    std::string ciphertext;
    if (method == "caesar")
    {

    }
    else if (method == "vigenere")
    {

    }
    else
    {
        std::cerr << "Error: method \"" << method << "\" not supported." << std::endl;
        retval = 1;
    }

    // Output
    output_file << ciphertext;
    return retval;
}


/* ===== MAIN ===== */

int main(int32_t argc, char* const* argv)
{
    // Final result
    int32_t retval = 0;

    // Process system arguments
    int32_t opt = 0;
    std::string method;
    std::string password;
    while ((opt = getopt(argc, argv, ":m:p:")) != -1)
    {
        switch(opt)
        {
            case 'm':
            {
                method = optarg;
                break;
            }
            case 'p':
            {
                password = optarg;
                break;
            }
            case ':':
                printf("option missing a value!\n");
                retval = 1;
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                retval = 1;
                break;
        }
    }

    // Check for errors in arguments
    if (method.empty())
    {
        printf("Error: No method given.\n");
        retval = 1;
    }
    if (password.empty())
    {
        printf("Error: No password given.\n");
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
            std::cout << "Use stdin and stdout" << std::endl;
            retval = ExecuteCipher(method, password, std::cin, std::cout);
        }
        else if (use_stdin)
        {
            std::cout << "Use stdin and file out: " << argv[optind + 1] << std::endl;
            std::ofstream outfile(argv[optind + 1]);
            retval = ExecuteCipher(method, password, std::cin, outfile);
        }
        else if (use_stdout)
        {
            std::cout << "Use file in: " << argv[optind] << " and stdout" << std::endl;
            std::ifstream infile(argv[optind]);
            retval = ExecuteCipher(method, password, infile, std::cout);
        }
        else
        {
            std::cout << "Use file in: " << argv[optind]
                        << " and file out" << argv[optind + 1] << std::endl;
            std::ifstream infile(argv[optind]);
            std::ofstream outfile(argv[optind + 1]);
            retval = ExecuteCipher(method, password, infile, outfile);
        }
    }

    return retval;
}



