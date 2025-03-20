#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <iostream>
#include <istream>
#include <limits>
#include <ostream>

namespace prompt {

constexpr int INT_MIN = std::numeric_limits<int>::min();
constexpr int INT_MAX = std::numeric_limits<int>::max();

char get_char_option(const char*   options,
                     std::istream& istream = std::cin,
                     std::ostream& ostream = std::cout);

int get_int(int min               = INT_MIN,
            int max               = INT_MAX,
            std::istream& istream = std::cin,
            std::ostream& ostream = std::cout);

std::string get_file_path(std::istream& istream = std::cin,
                          std::ostream& ostream = std::cout);

}    // namespace prompt

#endif