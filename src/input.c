#include "input.h"

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

/*
 * This helper function will trim the leading + trailing spaces of a string
 * This is done by iterating from the front and end until we reach a character
 * Then calling memmove to shrink the array in-place
 *
 *  int isspace(int argument);
 */

char *trimSpaces(char *str) {

    char *start = str;
    char *end;

    while (*start && isspace((char) *start)) {
        start++;
    }

    if (*start == '\0') {
        *str = '\0';
        return str;
    }

    end = start + strlen(start) - 1;
    while (end > start && isspace((char) *end)) {
        end--;
    }

    *(end + 1) = '\0';

    if (start != str) {
        memmove(str, start, end - start + 2);
    }
    return str;
}

bool isAlphaNumericSpaces(char *taskName) {
    int index = 0;
    bool hasLetter = false;

    while (taskName[index] != '\0') {
        if (isalpha((unsigned char)taskName[index])) {
            hasLetter = true;
        } else if (taskName[index] != ' ') {
            return false;
        }
        index++;
    }
    return hasLetter;
}