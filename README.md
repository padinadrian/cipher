# cipher
Command line tool for simple encryption ciphers

## Usage
The command interface is simple: you provide an encryption method, a passkey,
and an option filename for input or output files.

If no filename for input is given, stdin is used.
If no filename for output is given, stdout is used.

Run with `-h` for more details.

### Example 1:

File: hello.txt
```
HELLOWORLD
```

Run the cipher program:
```
cipher -m vigenere -p KEY hello.txt
```

Output:
```
RIJVSUYVJN
```

### Example 2:
```
echo "MYSUPERSECRETSTUFF" | cipher -m caesar -p B | cipher -m caesar -p Z
```

Output:
```
MYSUPERSECRETSTUFF
```

Supported ciphers are:
* Caesar cipher
* Vigenere cipher

## Dependencies
The following programs/libraries are needed to build from source and run the unit tests:
* C++ compiler (such as g++)
* make
* cmake
* googletest (aka gtest)

You can install the dependencies with the following command:

On Ubuntu:
```bash
sudo apt-get update
sudo apt-get install build-essential cmake libgtest-dev
```

## Building and Installing
This project uses cmake to generate the build system. Included in the repository
is a script to automate the cmake generation process (see [build.sh](build.sh))

To build the project:
```bash
# 1. Clone the repository:
git clone https://github.com/padinadrian/cipher.git

# 2. Run the generation script:
cd cipher
chmod +x build.sh
./build.sh

#3. Run make to build all:
cd build.local
make

#4. To install at /usr/local/bin/cipher (optional):
sudo make install
```

This will place both the cipher program and the unit tests in the bin folder at
`bin/cipher` and `bin/cipher_tests` respectively. By running the `make install`
command you can also install cipher to your applcation path so that it can be
used from the commandline from anywhere.

## Running unit tests
The unit tests for cipher use gtest, which needs to be installed separately (see
Dependencies above).

You can run the tests directly from the build folder:
```bash
bin/cipher_tests
```

Or, you can also use this convenience script which automatically rebuilds the tests
before running:
```bash
./run_tests.sh
```

# Future work
- [x] Installation instructions
- [ ] Support for direct decryption
- [ ] Support additional ciphers
