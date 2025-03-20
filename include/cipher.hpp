#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
namespace cipher {

enum Mode { UNSET, ENCRYPT, DECRYPT };

char        shift_char(char initial, int offset);
std::string shift_str(std::string& str, int offset);

}    // namespace cipher

#endif