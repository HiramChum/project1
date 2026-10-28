#ifndef USER_H
#define USER_H

typedef struct User
{
    char name[20];
    char password[20];
    int id;
    struct User *next;
} user_t, *user_ptr_t;

#endif