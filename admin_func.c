#include<stdio.h>
#include"book.h"
#include"user.h"

void function_admin(book_ptr_t head)
{   
    function_admin:
    int choice;
    enum admin_menu_choice
    {
        图书信息显示 = 1,
        图书信息删除,
        图书信息录入,
        图书信息更新,
        退出系统
    };
    printf("1. 图书信息显示\n");
    printf("2. 图书信息删除\n");
    printf("3. 图书信息录入\n");
    printf("4. 图书信息更新\n");
    printf("5. 退出系统\n");
    printf("欢迎管理员登录！请选择功能：\n");
    
    if(scanf("%d", &choice) != 1)
    {
        printf("输入无效，请输入 1、2、3、4 或 5。\n");
        return;
    }
    switch (choice)
    {
        case 图书信息显示:
            display_books(head);
            break;
        case 图书信息删除:
            delete_book(&head);
            break;
        case 图书信息录入:
            add_book(&head);
            break;
        case 图书信息更新:
            update_book(&head);
            break;
        case 退出系统:
            printf("感谢使用！\n");
            return;
        default:
            printf("无效选择,退出重试\n");
            goto function_admin; // 重新显示菜单
    }                           
}