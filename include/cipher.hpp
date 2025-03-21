#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
namespace cipher {

enum Mode { DECRYPT = -1, UNSET = 0, ENCRYPT = 1 };

char        shift_char(char initial, int offset);
std::string shift_str(std::string& str, int offset);

}    // namespace cipher

#endif