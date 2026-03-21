#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "gantt.h"
#include "input.h"

#define MAXARRAY 256

int main(void) {
    printf("Welcome to the CTaskManager\n");

    char UserInput[MAXARRAY];

    while (1) {
        printf("Would you like to see an example of a Gantt Chart? (Yes or No)\n");

        if (fgets(UserInput,sizeof(UserInput),stdin) == NULL) {
            return 1;
        }
        removeNewline(UserInput);

        if (strcasecmp("Yes", UserInput) == 0 || strcasecmp("No", UserInput) == 0) {
            if (strcasecmp("Yes", UserInput) == 0) {
                print_testExample();
            }
            break;
        }

        printf("Invalid Input!\n");
        }

    return 0;
}