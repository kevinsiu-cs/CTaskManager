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

int getNumOfTasks(void) {
    char userInput[MAXARRAY];
    int value;

    while (1) {
        printf("How many Tasks would you like to add? (1-10)\n");

        if (fgets(userInput,MAXARRAY,stdin) == NULL) {
            printf("fgets Error\n");
            return -1;
        }

        if (sscanf(userInput,"%d",&value) == 1) {
            if (value > 0 && value <= MAXTASKS) {
                return value;
            }
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

           if (fgets(userTasks[i].taskName,MAXARRAY,stdin) == NULL) {
               printf("fgets Error\n");
               return;
           }

            char *currentTaskName = userTasks[i].taskName;

            removeNewline(currentTaskName);
            trimSpaces(currentTaskName);

            if (currentTaskName[0] == '\0') {
                printf("Task name is empty\n");
                continue;
            }

            if (!isAlphaNumericSpaces(trimSpaces(currentTaskName))){
                printf("Invalid task name, Please only use Alphabetical characters and numbers\n");
                continue;
            }

            int currentTaskID = userTasks[i].taskID;
            userTasks[i].taskID = taskIDCounter++;
            break;
        }

        while (1) {
            /*
            printf("Who do you want to assign this task to? \n");

            if (fgets(userTasks[i].ownerID,MAXARRAY,stdin) == NULL) {
                printf("fgets Error\n");
                return;
            }



            /*
             * This function will be implemented later when as we will need to check
             * if the person exists before assigning them a specific task.
             *
             */

            int holder = 1;
            userTasks[i].ownerID = holder++;
            break;
        }


        while (1) {
            char userInput[MAXARRAY]; //fgets expects a string, so we cant pass userTask.startMonth
            int currentMonth;

            printf("Start month (1 - 12): \n");

            if (fgets(userInput,MAXARRAY,stdin) == NULL) {
                printf("fgets Error\n");
                return;
            }

            removeNewline(userInput);
            if (sscanf(userInput, "%d",&currentMonth) != 1) {
                printf("Invalid number, please enter a number between 1 - 12\n");
                continue;
            }

            if (currentMonth < 1 || currentMonth > 12) {
                printf("Invalid number, please enter a number between 1 - 12\n");
                continue;
            }

            userTasks[i].startMonth = currentMonth;
            break;
        }

        while (1) {
            char userInput[MAXARRAY];
            int currentMonth;

            printf("End month (1 - 12): \n");

            if (fgets(userInput,MAXARRAY,stdin) == NULL) {
                printf("fgets Error\n");
                return;
            }

            removeNewline(userInput);

            if (sscanf(userInput, "%d",&currentMonth) != 1) {
                printf("Invalid input, please enter a number between %d - 12\n", userTasks[i].startMonth);
                continue;
            }

            if (currentMonth < userTasks[i].startMonth || currentMonth > 12) {
                printf("Invalid input, please enter a number between %d - 12\n", userTasks[i].startMonth);
                continue;
            }
            userTasks[i].endMonth = currentMonth;
            break;
        }

                if (i == 0) {
            printf("The first task cannot have dependencies, we will set it to 0\n");
            userTasks[i].numOfDependencies = 0;
        } else {
            while (1) {
                char userInput[MAXARRAY];
                int currentNumOfDependencies;

                printf("Enter the number of dependent tasks (0 if none):\n");

                if (fgets(userInput, MAXARRAY, stdin) == NULL) {
                    printf("fgets Error\n");
                    return;
                }

                removeNewline(userInput);

                if (sscanf(userInput, "%d", &currentNumOfDependencies) != 1) {
                    printf("Invalid input. Enter a number between 0 and %d.\n", i);
                    continue;
                }

                if (currentNumOfDependencies < 0 || currentNumOfDependencies > i) {
                    printf("Invalid input. Enter a number between 0 and %d.\n", i);
                    continue;
                }

                userTasks[i].numOfDependencies = currentNumOfDependencies;
                break;
            }
        }

        for (int dependentLoop = 0; dependentLoop < userTasks[i].numOfDependencies; dependentLoop++) {
            while (1) {
                char userInput[MAXARRAY];
                int currentDependency;

                printf("Enter dependent task index (0 - %d):\n", i - 1);

                if (fgets(userInput, MAXARRAY, stdin) == NULL) {
                    printf("fgets Error\n");
                    return;
                }

                removeNewline(userInput);

                if (sscanf(userInput, "%d", &currentDependency) != 1) {
                    printf("Invalid input. Please enter a valid task index between 0 and %d.\n", i - 1);
                    continue;
                }

                if (currentDependency < 0 || currentDependency >= i) {
                    printf("Invalid input. Please enter a valid task index between 0 and %d.\n", i - 1);
                    continue;
                }

                userTasks[i].dependantTasks[dependentLoop] = currentDependency;
                break;
            }
        }

    }
}

void printTask(const Tasks *task) {
    int i;

    printf("Task Details:\n");
    printf("taskID: %d\n", task->taskID);
    printf("taskName: %s\n", task->taskName);
    printf("ownerID: %d\n", task->ownerID);
    printf("startMonth: %d\n", task->startMonth);
    printf("endMonth: %d\n", task->endMonth);
    printf("numOfDependencies: %d\n", task->numOfDependencies);


    printf("dependantTasks: ");
    if (task->numOfDependencies <= 0) {
        printf("None");
    } else {
        for (i = 0; i < task->numOfDependencies; i++) {
            printf("%d", task->dependantTasks[i]);
            if (i < task->numOfDependencies - 1) {
                printf(", ");
            }
        }
    }
    printf("\n");
}