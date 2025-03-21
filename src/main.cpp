#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "cipher.hpp"
#include "prompt.hpp"

int main(int argc, char* argv []) {
    int          offset = 0;
    std::string  input;
    std::string  input_file_name;
    std::string  output_file_name;
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
                input_file_name = argv [++i];
            }
        } else if (arg == "-o") {
            if (i + 1 < argc) { output_file_name = argv [++i]; }
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

    // configure output stream of either cout or the output file
    std::ostream* output_stream_ptr = &std::cout;
    std::ofstream output_file_stream;

    if (!output_file_name.empty()) {
        output_file_stream.open(output_file_name);
        output_stream_ptr = &output_file_stream;
    }

    if (input.empty()) {
        // handle file inputs
        if (input_file_name.empty()) {
            std::cout << "Enter input file path: ";
            input_file_name = prompt::get_file_path();
        }

        // read file and cipher as we go
        std::ifstream input_file_stream(input_file_name);

        std::string line;

        while (std::getline(input_file_stream, line)) {
            input_file_stream >> line;

            std::string ciphered_line = cipher::shift_str(line,
                                                          offset * mode);
            *output_stream_ptr << ciphered_line;
        }
    } else {
        // handle direct text input
    }

    return 0;
}