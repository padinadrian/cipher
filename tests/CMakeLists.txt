# CMake file for unit test executable

# List unit test source files
add_executable(${PROJECT_NAME}_tests
    cipher_utils_1_test.cpp
    caesar_1_test.cpp
    vigenere_1_test.cpp
    rail_fence_1_test.cpp
    scytale_1_test.cpp
    columnar_1_test.cpp
)

# Add dependent libraries
target_link_libraries(${PROJECT_NAME}_tests
    gtest
    gtest_main
    pthread
)
