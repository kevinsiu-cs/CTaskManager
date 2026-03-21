#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "gantt.h"
#include "input.h"

#define MAXARRAY 256

int main(void) {
    printf("Welcome to the CTaskManager\n");

    char userInput[MAXARRAY];

    while (1) {
        printf("Would you like to see an example of a Gantt Chart? (Yes or No)\n");

        if (fgets(userInput,sizeof(userInput),stdin) == NULL) {
            return -1;
        }
        removeNewline(userInput);

        if (strcasecmp("Yes", userInput) == 0 || strcasecmp("No", userInput) == 0) {
            if (strcasecmp("Yes", userInput) == 0) {
                print_testExample();
            }
            break;
        }

        printf("Invalid Input!\n");
        }

    int taskNum = getTaskNum();
    //printf("%d\n", taskNum);

    return 0;
}