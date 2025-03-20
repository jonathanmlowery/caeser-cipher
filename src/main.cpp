#include <iostream>
#include <string>

#include "cipher.hpp"

int main(int argc, char* argv []) {
    int          offset;
    std::string  input;
    std::string  input_file;
    std::string  output_file;
    cipher::Mode mode;

    // TODO: refactor this garbage
    // configure inputs given as execution arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv [i];
        if (arg == "-D" || arg == "-E") {
            mode = arg == "-D" ? cipher::DECRYPT     // -D
                               : cipher::ENCRYPT;    // -E

            if (i + 1 < argc && argv [i + 1][0] != '-') {
                input = argv [++i];
            }
        } else if (arg == "-d" || arg == "-e") {
            mode = arg == "-d" ? cipher::DECRYPT     // -d
                               : cipher::ENCRYPT;    // -e

            if (i + 1 < argc && argv [i + 1][0] != '-') {
                input_file = argv [++i];
            }
        } else if (arg == "-o") {
            if (i + 1 < argc) { output_file = argv [++i]; }
        } else if (arg == "-k") {
            if (i + 1 < argc) {
                offset = std::stoi(argv [++i]);
            }
        }
    }

    std::cout << mode << '\n';
    std::cout << input << '\n';
    std::cout << input_file << '\n';
    std::cout << output_file << '\n';
    std::cout << offset << '\n';

    return 0;
}