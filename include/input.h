#include <stdio.h>
#include <strings.h>
#include <string.h>
#include<stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXARRAY 256
#define MAXTASKS 10


void removeNewline(char *str);
char *trimSpaces(char *str);
bool isAlphaNumericSpaces(char *str);

void clearScreen();