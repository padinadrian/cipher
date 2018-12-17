# CMake file for unit test executable

# List unit test source files
add_executable(${PROJECT_NAME}_test
    cipher_utils_1_test.cpp
    caesar_1_test.cpp
    vigenere_1_test.cpp
)

# Add dependent libraries
target_link_libraries(${PROJECT_NAME}_test
    gtest
    gtest_main
    pthread
)
