#!/usr/bin/env bash

BUILD_DIR="build.local"
TEST_FILENAME="$BUILD_DIR/bin/cipher_tests"

rm $TEST_FILENAME
make cipher_tests -C $BUILD_DIR
$TEST_FILENAME
