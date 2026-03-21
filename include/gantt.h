#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 100
#define MAXTASKS 10



typedef struct {
    int taskID;
    char taskName[MAXSIZE];
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

int getTaskNum(void);
void getTaskInfo(Tasks userTasks[], int taskNum);

