#ifndef CIPHER_HPP
#define CIPHER_HPP

namespace cipher {

enum Mode { UNSET, ENCRYPT, DECRYPT };

char shift_char(char initial, int offset);

}    // namespace cipher

#endif