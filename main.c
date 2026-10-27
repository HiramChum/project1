#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int main()
{
    int operation;
    user_t admin = {"admin", "", 0, NULL};
    user_ptr_t admin_ptr = &admin; //头指针
    int next_user_id = 1;
set_admin_password:
    printf("请设置管理员密码：");
    if (scanf("%19s", admin.password) != 1)
    {
        printf("密码输入无效，请重新输入：\n");
        goto set_admin_password;
    }

    while (1)
    {
        printf("你好！，欢迎使用图书管理系统！\n");
        enum { 登录 = 1, 注册, 退出 };
        printf("请选择操作：1.登录 2.注册 3.退出\n");
        if (scanf("%d", &operation) != 1)
        {
            printf("输入无效，请输入 1、2 或 3。\n");
            continue;
        }
        switch (operation)
        {
        case 登录:
        {
            user_ptr_t logged_in_user = login_user(users);
            if (logged_in_user != NULL)
            {
                if (logged_in_user->id == 0)
                {
                    printf("管理员登录成功。\n");
                }
                else
                {
                    printf("普通用户登录成功。\n");
                }
            }
            break;
        }
        case 注册:
            sign_up(admin_ptr, &next_user_id);
            break;
        case 退出:
            return 0;
        default:
            printf("无效的操作。\n");
            continue;
        }
    }
}