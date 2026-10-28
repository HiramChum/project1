#include "user.h"
#include <stdio.h>
#include <string.h>
void sign_up(user_ptr_t head_ptr, int *next_user_id_ptr);

int user_login(user_ptr_t head_ptr, int *next_user_id_ptr) // 0管理员登录成功 1普通用户登录成功
{
    char name[20];
    char password[20];
input:
    printf("请输入用户名，还未有账号？按#前往注册：");

    if (scanf("%19s", name) != 1)
    {
        printf("输入无效，登录失败！\n");
        goto input;
        return 0;
    }

    if (strcmp(name, "#") == 0)
    {
        printf("开始注册\n");
        sign_up(head_ptr, next_user_id_ptr);
    }

    printf("请输入密码：");
    if (scanf("%19s", password) != 1)
    {
        printf("输入无效，登录失败！\n");
        goto input;
        return 0;
    }

    if (strcmp(head_ptr->name, name) == 0 && strcmp(head_ptr->password, password) == 0)
    {
        printf("欢迎管理员！\n");
        return 0;
    }

    for (user_ptr_t current = head_ptr; current != NULL; current = current->next)
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
}