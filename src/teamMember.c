#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "teamMember.h"
#include "input.h"

void addMember(struct teamMember **teamHeadAddress) {

    static int currentID = 1;

    teamMember *newMember = malloc(sizeof(struct teamMember));
    if (newMember == NULL) {return;}

    newMember->memberID = currentID++;

    char userInput[MAXARRAY];






}