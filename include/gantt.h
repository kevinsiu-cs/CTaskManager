#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXARRAY 256
#define MAXTASKS 10



typedef struct {
    int taskID;
    char taskName[MAXARRAY];
    int ownerID;
    int startMonth;
    int endMonth;
    int numOfDependencies;
    int dependantTasks[MAXTASKS];
}Tasks;

/*
 * Creation of the example Gantt Chart + General Formatting:
*/
void print_topBorder(void);
void print_Header(void);
void print_spacedLine(void);
void print_testExample(void);

int getNumOfTasks(void);
void getTaskInfo(Tasks userTasks[], int taskNum);

void printTask(const Tasks *task);

