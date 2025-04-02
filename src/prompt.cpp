#include "prompt.hpp"

#include <cstring>
#include <filesystem>
#include <string>

// #include <ostream>

namespace prompt {    // prompts to keep asking user for valid input

/**
 * Keeps asking the user to pick a
 * character option until they pick one in
 * of the choices given
 * @param options Array of chars that each represent a choice for the user
 * @param istream Input stream (defaults to std::cin)
 * @param ostream Output stream (defaults to std::cout)
 * @return char option that was selected
 */
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

/**
 * Keeps asking the user to enter an integer
 * until they provide a valid one
 * @param min Minimum integer value to be accepted
 * @param max Maximum integer value to be accepted
 * @param istream Input stream (defaults to std::cin)
 * @param ostream Output stream (defaults to std::cout)
 * @return int provided by the user
 */
int get_int(int min, int max, std::istream& istream, std::ostream& ostream) {

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

/**
 * Keeps asking the user to enter the path of
 * an input file until they provide a valid one
 * @param istream Input stream (defaults to std::cin)
 * @param ostream Output stream (defaults to std::cout)
 * @return string of path to valid file
 */
std::string get_file_path(std::istream& istream, std::ostream& ostream) {
    std::string file_path;

    while (true) {
        std::getline(istream, file_path);

        if (std::filesystem::is_regular_file(file_path)) { return file_path; }

        ostream << "Invalid file path.\nTry again: ";
    }
}

}    // namespace prompt