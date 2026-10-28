#include "user.h"
#include <stdio.h>
#include <string.h>

int user_login(user_ptr_t head)
{
    char name[20];
    char password[20];
    input:
    printf("请输入用户名：");
    if (scanf("%19s", name) != 1)
    {
        printf("输入无效，登录失败！\n");
        goto input;
        return 0;
    }

    printf("请输入密码：");
    if (scanf("%19s", password) != 1)
    {
        printf("输入无效，登录失败！\n");
        goto input;
        return 0;
    }

    for (user_ptr_t current = head; current != NULL; current = current->next)
    {
        if (strcmp(current->name, name) == 0 &&
            strcmp(current->password, password) == 0)
        {
            printf("登录成功！\n");
            return 1;
        }
    }

    printf("用户名或密码错误，登录失败！\n");
    goto input;
    return 0;
}