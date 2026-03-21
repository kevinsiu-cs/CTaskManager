#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 100
#define MAXTASKS 10



typedef struct {
    char task[MAXSIZE];
    int ownerID;
    int startMonth;
    int endMonth;
    int numOfDependancies;
    int dependantTasks[MAXTASKS];
}Tasks;

/*
 * Creation of the example Gantt Chart:
*/
void print_topBorder(void);
void print_Header(void);
void print_spacedLine(void);
void print_testExample(void);

