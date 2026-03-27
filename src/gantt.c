#include "gantt.h"
#include "teamMember.h"
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
    clearScreen();
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
        {10,"Snagging", 5,8, 10, 2, {7, 8}},
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

int getTaskName(Tasks *task) {
    clearScreen();
    while (1) {
        printf("Enter the task name: \n");

        if (fgets(task->taskName, MAXARRAY, stdin) == NULL) {
            printf("fgets Error\n");
            return 0;
        }

        char *currentTaskName = task->taskName;

        removeNewline(currentTaskName);
        trimSpaces(currentTaskName);

        if (currentTaskName[0] == '\0') {
            printf("Task name is empty\n");
            continue;
        }

        if (!isAlphaNumericSpaces(currentTaskName)) {
            printf("Invalid task name, Please only use Alphabetical characters and numbers\n");
            continue;
        }

        return 1;
    }
}


int getStartMonth(Tasks *task){
    clearScreen();
    while (1) {
        char userInput[MAXARRAY]; //fgets expects a string, so we cant pass userTask.startMonth
        int currentMonth;

        printf("Start month (1 - 12): \n");

        if (fgets(userInput, MAXARRAY, stdin) == NULL) {
            printf("fgets Error\n");
            return 0;
        }

        removeNewline(userInput);
        if (sscanf(userInput, "%d", &currentMonth) != 1) {
            printf("Invalid number, please enter a number between 1 - 12\n");
            continue;
        }

        if (currentMonth < 1 || currentMonth > 12) {
            printf("Invalid number, please enter a number between 1 - 12\n");
            continue;
        }

        task->startMonth = currentMonth;
        return 1;
    }
}

int getEndMonth(Tasks *task){
    clearScreen();
    while (1) {
        char userInput[MAXARRAY];
        int currentMonth;

        printf("End month (%d - 12): \n",task->startMonth);

        if (fgets(userInput, MAXARRAY, stdin) == NULL) {
            printf("fgets Error\n");
            return 0;
        }

        removeNewline(userInput);

        if (sscanf(userInput, "%d", &currentMonth) != 1) {
            printf("Invalid input, please enter a number between %d - 12\n", task->startMonth);
            continue;
        }

        if (currentMonth < task->startMonth || currentMonth > 12) {
            printf("Invalid input, please enter a number between %d - 12\n",task->startMonth);
            continue;
        }
        task->endMonth = currentMonth;
        return 1;
    }
}

int getNumOfDependencies(Tasks *task, int totalExistingTasks) {
    clearScreen();
    if (totalExistingTasks == 0) {
        printf("This is the first task in the project; it cannot have dependencies.\n");
        task->numOfDependencies = 0;
        return 1;
    }

    while (1) {
        char userInput[MAXARRAY];
        int count;

        int limit;

        if (totalExistingTasks < MAXTASKS) {
            limit = totalExistingTasks;
        } else {
            limit = MAXTASKS;
        }

        printf("Enter the number of dependent tasks (0 - %d):\n", limit);

        if (fgets(userInput, MAXARRAY, stdin) == NULL) {
            printf("fgets Error\n");
            return 0;
        }

        removeNewline(userInput);

        if (sscanf(userInput, "%d", &count) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (count < 0 || count > limit) {
            printf("Invalid input. Enter a number between 0 and %d.\n", limit);
            continue;
        }

        task->numOfDependencies = count;
        return 1;
    }
}

int getDependencyIndexes(Tasks *task, int totalExistingTasks) {
    clearScreen();
    if (task->numOfDependencies == 0) {
        return 1;
    }

    for (int i = 0; i < task->numOfDependencies; i++) {
        while (1) {
            char userInput[MAXARRAY];
            int depID;

            printf("Enter dependent task ID (1 - %d): ", totalExistingTasks);

            if (fgets(userInput, MAXARRAY, stdin) == NULL) {
                printf("fgets Error\n");
                return 0;
            }

            removeNewline(userInput);

            if (sscanf(userInput, "%d", &depID) != 1) {
                printf("Invalid input. Please enter a valid Task ID.\n");
                continue;
            }

            if (depID < 1 || depID > totalExistingTasks) {
                printf("Invalid ID. You can only depend on existing tasks (1 - %d).\n", totalExistingTasks);
                continue;
            }

            //store based on 0 indexing.
            task->dependantTasks[i] = depID - 1;
            break;
        }
    }
    return 1;
}

//this function is needed for the limit
int countTotalTasks(struct teamMember *teamHead) {
    int count = 0;

    struct teamMember *currMem = teamHead;

    while (currMem != NULL) {
        Tasks *currTask = currMem->firstTask;
        while (currTask != NULL) {
            count++;
            currTask = currTask->nextTask;
        }
        currMem = currMem->nextMember;
    }
    return count;
}


void addTask(struct teamMember *teamHead) {
    clearScreen();
    if (teamHead == NULL) {
        printf("Error: You must add a team member first!\n");
        return;
    }

    displayAllMembersAndTasks(teamHead);
    static int globalTaskID = 1;

    int ownerID;
    char input[MAXARRAY];
    printf("Enter the Member ID to assign this task to: ");
    if (fgets(input, MAXARRAY, stdin) == NULL) {
        printf("fgets Error\n");
        return;
    }

    if (sscanf(input, "%d", &ownerID) != 1) {
        printf("Invalid ID\n");
        return;
    }

    struct teamMember *currMem = teamHead;
    while (currMem != NULL && currMem->memberID != ownerID) {
        currMem = currMem->nextMember;
    }

    if (currMem == NULL) {
        printf("Member ID %d not found.\n", ownerID);
        return;
    }

    Tasks *newTask = malloc(sizeof(Tasks));
    if (!newTask) {
        printf("Memory allocation failed.\n");
        return;
    }

    newTask->taskID = globalTaskID++;
    newTask->ownerID = ownerID;
    newTask->nextTask = NULL; //first task


    if (!getTaskName(newTask)){
        free(newTask); return;
    }
    if (!getStartMonth(newTask)){
        free(newTask); return;
    }
    if (!getEndMonth(newTask)) {
        free(newTask); return;
    }


    int totalTasks = countTotalTasks(teamHead);

    if (!getNumOfDependencies(newTask, totalTasks)){
        free(newTask); return;
    }
    if (!getDependencyIndexes(newTask, totalTasks)) {
        free(newTask); return;
    }

    //link task to the member
    if (currMem->firstTask == NULL) {
        currMem->firstTask = newTask;
    } else {
        Tasks *temp = currMem->firstTask;
        while (temp->nextTask != NULL) {
            temp = temp->nextTask;
        }
        temp->nextTask = newTask;
    }
    printf("Task ID %d ('%s') added to %s.\n", newTask->taskID, newTask->taskName, currMem->memberName);
}


void printUserGantt(void) {
    clearScreen();
    printf("printUserGantt is not implemented yet.\n");
}