#include "input.h"

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}