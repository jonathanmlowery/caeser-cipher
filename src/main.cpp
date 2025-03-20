#include <iostream>
#include <string>

#include "cipher.hpp"
#include "prompt.hpp"

int main(int argc, char* argv []) {
    int          offset = 0;
    std::string  input;
    std::string  output;
    std::string  input_file;
    std::string  output_file;
    cipher::Mode mode = cipher::UNSET;

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
            if (i + 1 < argc) { offset = std::stoi(argv [++i]); }
        }
    }

    // prompt user for any inputs still needed
    // TODO: refactor this too

    if (mode == cipher::UNSET) {
        std::cout << "Enter e to encrypt, d to decrypt: ";
        switch (prompt::get_char_option("ed")) {
            case 'e':
                mode = cipher::ENCRYPT;
                break;
            case 'd':
                mode = cipher::DECRYPT;
                break;
        }
    }

    if (offset > 25 || offset < 1) {
        std::cout << "Enter a key value between 1 and 25: ";
        offset = prompt::get_int(1, 25);
    }

    if (input.empty()) {
        // handle file inputs
        if (input_file.empty()) {
            std::cout << "Enter input file path: ";
            input_file = prompt::get_file_path();
        }

        // read file and cipher as we go
    } else {
        // handle direct text input
    }

    return 0;
}