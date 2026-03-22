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

        if (fgets(userInput,MAXARRAY,stdin) == NULL) {
            return -1;
        }
        removeNewline(userInput);
        trimSpaces(userInput);

        if (strcasecmp("Yes", userInput) == 0 || strcasecmp("No", userInput) == 0) {
            if (strcasecmp("Yes", userInput) == 0) {
                print_testExample();
            }
            break;
        }

        printf("Invalid Input!\n");
        }

    int taskNum = getNumOfTasks();
    Tasks userTaskArray[taskNum];
    //printf("%d\n", taskNum);

    getTaskInfo(userTaskArray,taskNum);
    printTask(userTaskArray,taskNum);

    return 0;
}