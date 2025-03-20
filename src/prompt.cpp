#include "prompt.hpp"

#include <cstring>
#include <filesystem>
#include <string>

// #include <ostream>

namespace prompt {

char get_char_option(const char*   options,
                     std::istream& istream,
                     std::ostream& ostream) {

    std::string input;

    while (true) {
        std::getline(istream, input);

        if (input.length() != 1) {
            ostream << "Enter only one character.\nTry again: ";
            continue;
        }

        if (!std::strchr(options, input [0])) {
            ostream << "Not a valid option.\nTry again: ";
            continue;
        }

        return input [0];
    }
}

int get_int(int           min,
            int           max,
            std::istream& istream,
            std::ostream& ostream) {

    int input;

    while (true) {
        istream >> input;

        if (istream.fail()) {
            // handles invalid data type input
            ostream << "Invalid input type.\nTry again: ";

            istream.clear();
            istream.ignore(INT_MAX, '\n');
        } else if (input > max || input < min) {
            // handles input outside interval [min, max]
            ostream << "Outside input range.\nTry again: ";

            istream.ignore(INT_MAX, '\n');
        } else {
            // returns valid input
            istream.ignore(INT_MAX, '\n');

            return input;
        }
    }
}

std::string get_file_path(std::istream& istream, std::ostream& ostream) {
    std::string file_path;

    while (true) {
        std::getline(istream, file_path);

        if (std::filesystem::is_regular_file(file_path)) {
            return file_path;
        }

        ostream << "Invalid file path.\nTry again: ";
    }
}

}    // namespace prompt