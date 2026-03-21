#include "gantt.h"
#include "input.h"

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

    Tasks exampleTask[] = {
        {1,"Find_Bank",1, 1,2, 0, {}},
        {2,"Get_Mortgage_approval",2, 2, 2, 1, {0}},
        {3,"Draw_down",3,4,6,2,{0,1}},
        {4,"Build_Foundation",3,3,4, 1,{2}},
        {5,"Build_walls", 4, 5, 0,0, {}},
        {6,"Roof_and_Ceiling", 1,5, 6, 2, {3, 4}},
        {7,"Plumbing", 5,7, 7, 1, {5}},
        {8,"Electrics", 2,8, 9, 1, {6}},
        {9,"Inspect_Build", 4,9, 10, 1, {4}},
        {10,"Snagging", 5,3, 10, 2, {7, 8}},
        };

    for (int task_index = 0; task_index < MAXTASKS; task_index++) {

        Tasks currentTask = exampleTask[task_index];
        printf("%-24s", exampleTask[task_index].taskName);

        for (int i = 1; i <= 12; i++) {
            printf("|");
            if (i >= currentTask.startMonth && i <= currentTask.endMonth) {
                printf("  XXX  ");
            } else {
                printf("       ");
            }
        }

        printf(" | ");
        if (currentTask.numOfDependencies > 0) {
            for (int j = 0; j < currentTask.numOfDependencies; j++) {
                printf("%d ", currentTask.dependantTasks[j] + 1); // + 1, to ensure indexing is correct for user.
            }
        }

        printf("\n");
        print_spacedLine();
    }
}

int getTaskNum(void) {
    char userInput[MAXSIZE];
    int value;

    while (1) {
        printf("How many Tasks would you like to add? (1-10)\n");

        if (fgets(userInput,sizeof(userInput),stdin) == NULL) {
            return -1;
        }

        value = atoi(userInput);

        if (value > 0 && value <= MAXTASKS) {
            return value;
        }

        printf("Invalid Input!\n");
    }
}

void getTaskInfo(Tasks userTasks[], int taskNum) {

    int taskIDCounter = 1;
    //Hardcoding OwnerID for now -> Will Implement once person functionality is added.
    for (int i = 0; i < taskNum; i++) {

        while (1) {
            printf("Enter the task name: \n");
            fgets(userTasks[i].taskName,MAXSIZE,stdin);
            removeNewline((userTasks[i].taskName));

            char *currentTaskName = userTasks[i].taskName;

            if (strlen(currentTaskName) == 0) {
                continue;
            }

            if (!isAlphaNumericSpaces(currentTaskName)) {
                printf("Invalid task name, Please only use Alphabetical characters and numbers\n");
                continue;
            }
        }
    }
}