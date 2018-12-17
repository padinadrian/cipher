#!/usr/bin/env bash

BUILD_DIR="build.local"
TEST_FILENAME="$BUILD_DIR/bin/cipher_test"

make -C $BUILD_DIR
$TEST_FILENAME
