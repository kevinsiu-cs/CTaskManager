#ifndef GANTT_H
#define GANTT_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXARRAY 256
#define MAXTASKS 10

struct teamMember;

typedef struct Tasks{
    int taskID;
    char taskName[MAXARRAY];
    int ownerID;
    int startMonth;
    int endMonth;
    int numOfDependencies;
    int dependantTasks[MAXTASKS];
    struct Tasks *nextTask;
}Tasks;

/*
 * Creation of the example Gantt Chart + General Formatting:
*/
void print_topBorder(void);
void print_Header(void);
void print_spacedLine(void);
void print_testExample(void);

int getTaskName(Tasks *task);
int getStartMonth(Tasks *task);
int getEndMonth(Tasks *task);
int countTotalTasks(struct teamMember *teamHead);
int getNumOfDependencies(Tasks *task, int totalExistingTasks);
int getDependencyIndexes(Tasks *task, int totalExistingTasks);




void addTask(struct teamMember *teamHead);
void printTask(const Tasks userTasks[], int taskNum);
int compareTaskIDs(const void *a, const void *b);
void printUserGantt(struct teamMember *teamHead);

#endif
