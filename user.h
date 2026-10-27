#ifndef USER_H
#define USER_H

typedef struct User
{
    char name[20];
    char password[20];
    int id;
    struct User *next;
} user_t, *user_ptr_t;

void sign_up(user_ptr_t head, int *next_id);
user_ptr_t login_user(user_ptr_t head);
#endif