#include "gantt.h"

void print_topBorder(void) {
    for (int i = 0; i < 150; i++) {
        printf("_");
    }
    printf("\n");
}

void print_Header(void) {
    printf("%-24s|  Jan  |  Feb  |  Mar  |  Apr  |  May  |  Jun  |  Jul  |  Aug  |  Sep  |  Oct  |  Nov  |  Dec   | Dependencies\n", "");
}

void print_spacedLine(void) {
    for (int i = 0; i < 150; i++) {
        printf("-");
    }
    printf("\n");
}

void print_testExample(void) {
    print_topBorder();
    print_Header();
    print_spacedLine();

    Tasks exampletask[] = {
        {"Find_Bank", 1,2, 0, {}},
        {"Get_Mortgage_approval", 2, 2, 1, {0}},
        {"Draw_down",4,6,2,{0,1}},
        {"Build_Foundation",3,4, 1,{2}},
        {"Build_walls", 4, 5, 0, {}},
        {"Roof_and_Ceiling", 5, 6, 2, {3, 4}},
        {"Plumbing", 7, 7, 1, {5}},
        {"Electrics", 8, 9, 1, {6}},
        {"Inspect_Build", 9, 10, 1, {4}},
        {"Snagging", 9, 10, 2, {7, 8}},
        };

    for (int task_index = 0; task_index < MAXTASKS; task_index++) {

        printf("%-24s", exampletask[task_index].task);

        for (int i = 1; i <= 12; i++) {
            printf("|");
            if (i >= exampletask[task_index].startMonth && i <= exampletask[task_index].endMonth) {
                printf("  XXX  ");
            } else {
                printf("       ");
            }
        }

        printf(" | ");
        if (exampletask[task_index].numOfDependancies > 0) {
            for (int j = 0; j < exampletask[task_index].numOfDependancies; j++) {
                printf("%d ", exampletask[task_index].dependantTasks[j] + 1); // + 1, to ensure indexing is correct for user.
            }
        }

        printf("\n");
        print_spacedLine();
    }
}
