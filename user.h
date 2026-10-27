#ifndef USER_H
#define USER_H

#include <stdbool.h>

typedef struct User
{
    char name[20];
    char password[20];
    int id;
    int role; // role: 0 for admin, 1 for regular user
    struct User *next;
} User_t, *User_Ptr;

void sign_up(User_Ptr *head, int *next_id);
bool login_user(User_Ptr head, bool *is_admin);
#endif