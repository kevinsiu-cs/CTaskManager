#ifndef CTASKMANAGER_TEAMMEMBER_H
#define CTASKMANAGER_TEAMMEMBER_H

#define MAXARRAY 256
#define MAXUSERS 10

struct Tasks;
struct teamMember;

typedef struct teamMember{
    int memberID;
    char memberName[MAXARRAY];
    struct teamMember *nextMember;
    struct Tasks *firstTask;
}teamMember;


void addMember(struct teamMember **teamHeadAddress);
void removeMember(struct teamMember **teamHeadAddress);
void displayAllMembersAndTasks(struct teamMember *headMember);

#endif //CTASKMANAGER_USERS_H