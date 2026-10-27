#include "user.h"
#include <stdio.h>
#include <string.h>

bool login_user(User_Ptr head, bool *is_admin)
{
    char name[20];
    char password[20];

    if (is_admin == NULL)
    {
        return false;
    }
    *is_admin = false;

    printf("请输入用户名：");
    if (scanf("%19s", name) != 1)
    {
        printf("输入无效，登录失败！\n");
        return false;
    }

    printf("请输入密码：");
    if (scanf("%19s", password) != 1)
    {
        printf("输入无效，登录失败！\n");
        return false;
    }

    for (User_Ptr current = head; current != NULL; current = current->next)
    {
        if (strcmp(current->name, name) == 0 &&
            strcmp(current->password, password) == 0)
        {
            *is_admin = current->role == 0;
            return true;
        }
    }

    printf("用户名或密码错误，登录失败！\n");
    return false;
}