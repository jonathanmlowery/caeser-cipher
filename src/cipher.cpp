#include "cipher.hpp"

#include <string>

namespace cipher {
/**
 * Applies caeser cipher to an individual char
 * @param initial Input char
 * @param offset Number of letters to shift the input by
 * @return Ciphered char
 */
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

/**
 * Applies caeser cipher to an individual string
 * @param str Input string
 * @param offset Number of letters to shift each character by
 * @return Ciphered string
 */
std::string shift_str(std::string& str, int offset) {
    std::string shifted_str = "";

    for (int i = 0; i < str.length(); i++) {
        shifted_str += shift_char(str [i], offset);
    }

    return shifted_str;
}

}    // namespace cipher