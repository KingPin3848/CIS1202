#include <iostream>
#include <stdexcept>

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw std::invalid_argument("InvalidCharacterException: Start is not a letter.");
    }

    if (!isalpha(start + offset) || (isupper(start) && islower(start + offset)) || (islower(start) && isupper(start + offset))) {
        throw std::invalid_argument("InvalidRangeException: Target is not a letter or causes upper/lower case transition.");
    }

    return start + offset;
}

int main() {
    try {
        std::cout << "character('a', 1) returns: " << character('a', 1) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "character('a', -1) returns: " << character('a', -1) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "character('Z', -1) returns: " << character('Z', -1) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "character('?', 5) returns: " << character('?', 5) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "character('A', 32) returns: " << character('A', 32) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "character('.', -5) returns: " << character('.', -5) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "character('Z', -35) returns: " << character('Z', -35) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
