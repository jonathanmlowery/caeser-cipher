#include "cipher.hpp"

namespace cipher {

char shift_char(char initial, int offset) {
    int  alphabet_index;    // A -> 0, B -> 1, ...Z -> 25
    bool is_uppercase;

    if (65 <= initial && initial <= 90) {
        // uppercase letters
        alphabet_index = initial - 65;
        is_uppercase   = true;
    } else if (97 <= initial && initial <= 122) {
        // lowercase letters
        alphabet_index = initial - 97;
        is_uppercase   = false;
    } else {
        // the char is not a letter; must be some other kind of character
        // caeser cipher won't apply, so we will return the char without
        // change
        return initial;
    }

    int shifted_alphabet_index = (alphabet_index + offset + 26) % 26;

    return (shifted_alphabet_index + 65) + (!is_uppercase * 32);
}

}    // namespace cipher