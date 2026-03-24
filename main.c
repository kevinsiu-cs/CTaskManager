#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "gantt.h"
#include "input.h"
#include "teamMember.h"

#define MAXARRAY 256

void printMenu(void);

int main(void) {
    printf("Welcome to the CTaskManager\n");

    teamMember *memberHead = NULL; //init the teamMembers

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

    int menuChoice = -1;
    do {
        printMenu();

        if (fgets(userInput,MAXARRAY,stdin) == NULL) {
            break;
        }

        removeNewline(userInput);

        if (sscanf(userInput, "%d", &menuChoice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            menuChoice = -1;
            continue;
        }

        if (menuChoice == 6) break; // If user wants to exit, we don't have to go through all the other cases first

        if (menuChoice < 1 || menuChoice > 6) {
            printf("Please choose a number between 1 - 6\n");
        }else {
            switch (menuChoice) {
                case 1: addMember(&memberHead); break;
                case 2: removeMember(&memberHead); break;
                case 3: addTask(memberHead); break;
                case 4: printUserGantt(); break;
                case 5: displayAllMembersAndTasks(memberHead); break;
                default: break;
            }
        }
    }while (menuChoice != 6);
    return 0;
}

void printMenu(void) {
    printf("\n=== Menu ===\n");
    printf("1. Add a Team Member\n");
    printf("2. Remove a Team Member\n");
    printf("3. Add and Set a Task\n");
    printf("4. Show Current Gantt chart\n");
    printf("5. Show the Team Member and Tasks\n");
    printf("6. Exit\n");
}