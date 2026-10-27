#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int main() {
    int operation;
    User_t admin = {"admin", "", 0, 0, NULL};
    User_Ptr users = &admin;
    int next_user_id = 1;

    printf("请设置管理员密码：");
    if (scanf("%19s", admin.password) != 1) {
        printf("密码输入无效，程序退出。\n");
        return 1;
    }

    while (1) {
        printf("你好！，欢迎使用图书管理系统！\n");
        printf("请选择操作：1.登录 2.注册 3.退出\n");
        if (scanf("%d", &operation) != 1) {
            printf("输入无效，请输入 1、2 或 3。\n");
            return 1;
        }

        switch (operation) {
            case 1: {
                bool is_admin = false;
                if (login_user(users, &is_admin)) {
                    if (is_admin) {
                        printf("管理员登录成功。\n");
                    } else {
                        printf("普通用户登录成功。\n");
                    }
                }
                break;
            }
            case 2:
                sign_up(&users, &next_user_id);
                break;
            case 3:
                return 0;
            default:
                printf("无效的操作。\n");
                continue;
        }
    }

}