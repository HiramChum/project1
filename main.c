#include <stdio.h>

int main() {
    int operation;

    printf("你好！，欢迎使用图书管理系统！\n");
    printf("请选择操作：1.登录 2.注册 3.退出\n");
    enum Operation {
        登录 = 1,
        注册,
        退出
    };
    Operation:
    if (scanf("%d", &operation) != 1) {
        printf("输入无效，请输入 1 、2或 3。\n");
        return 1;
    }

    switch (operation) {
        case 登录:
            goto login;
            break;
        case 注册:
            goto register_user;
            break;
        case 退出:
            goto exit_program;
            break;
        default:
            printf("无效的操作。\n");
            goto Operation;
            break;
    }
    return 0;
}