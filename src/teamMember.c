#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "teamMember.h"
#include "input.h"
#include "gantt.h"  //needed to fix compilation issue with currTask -> TaskName


void addMember(struct teamMember **teamHeadAddress) {
    static int currentID = 1;
    char userInput[MAXARRAY];

    struct teamMember *newMember = malloc(sizeof(struct teamMember));
    if (newMember == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    while (1) {
        printf("Enter name for Team Member %d: ", currentID);

        if (fgets(userInput, MAXARRAY, stdin) == NULL) {
            free(newMember);
            return;
        }

        removeNewline(userInput);
        trimSpaces(userInput);

        if (strlen(userInput) > 0) {
            /**
             * If UserName is more than 50 characters, there will be an issue
             */

            strncpy(newMember->memberName, userInput, 50);
            newMember->memberName[49] = '\0';
            break;
        }

        printf("Invalid input. Name cannot be empty.\n");
    }

    newMember->memberID = currentID++;
    newMember->nextMember = NULL;
    newMember->firstTask = NULL;

    if (*teamHeadAddress == NULL) {
        // if List is empty, set new member to head
        *teamHeadAddress = newMember;
    } else {
        struct teamMember *temp = *teamHeadAddress;
        while (temp->nextMember != NULL) {
            temp = temp->nextMember;
        }
        temp->nextMember = newMember;
    }

    printf("Member '%s' added successfully with ID: %d\n", newMember->memberName, newMember->memberID);
}

void displayAllMembersAndTasks(struct teamMember *headMember) {
    struct teamMember *currentMember = headMember;

    printf("\n=== Team Members ===\n");

    if (currentMember == NULL) {
        printf("Team Members are empty.\n");
        return;
    }

    while (currentMember != NULL) {
        printf("Name: %s, ID: %d\n", currentMember->memberName, currentMember->memberID);
        printf("Tasks:\n");

        if (currentMember->firstTask == NULL) {
            printf("This Team Member doesn't have any tasks\n");
            return;
        }else {
            struct Tasks *currentTask = currentMember->firstTask;

            while (currentTask != NULL) {
                printf("Task: %s\n",currentTask->taskName);
            }
        }

        printf("===================");

        currentMember = currentMember->nextMember;
    }
}

void removeMember(struct teamMember **teamHeadAddress) {
    printf("removeMember is not implemented yet.\n");
}