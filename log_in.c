#include "user.h"
#include <stdio.h>
#include <string.h>

user_ptr login_user(user_ptr head)
{
    char name[20];
    char password[20];

    printf("请输入用户名：");
    if (scanf("%19s", name) != 1)
    {
        printf("输入无效，登录失败！\n");
        return NULL;
    }

    printf("请输入密码：");
    if (scanf("%19s", password) != 1)
    {
        printf("输入无效，登录失败！\n");
        return NULL;
    }

    for (user_ptr current = head; current != NULL; current = current->next)
    {
        if (strcmp(current->name, name) == 0 &&
            strcmp(current->password, password) == 0)
        {
            return current;
        }
    }

    printf("用户名或密码错误，登录失败！\n");
    return NULL;
}