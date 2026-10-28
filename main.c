#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "book.h"
#include "book_borrow.h"
#include "input_utils.h"
int user_login(user_ptr_t head_ptr, int *next_id_ptr, int *logged_in_user_id);
void sign_up(user_ptr_t head_ptr, int *next_user_id_ptr);
int admin_book_delete(book_ptr_t head_ptr, book_borrow_ptr_t borrow_head);
int book_list_create(book_ptr_t head_ptr, int *next_book_id_ptr);
int admin_book_update(book_ptr_t head_ptr, book_borrow_ptr_t borrow_head);
void book_list_review(book_ptr_t head_ptr);
void book_search(book_ptr_t head);
void book_borrow(book_borrow_ptr_t borrow_head, book_ptr_t book_head, int user_id);
void book_return(book_borrow_ptr_t head, int user_id);
void book_borrow_review(book_borrow_ptr_t head, int user_id);
int main()
{
    user_t admin = {"admin", "", 0, NULL}; // 管理员是0号用户
    user_ptr_t admin_ptr = &admin;
    int next_user_id = 1;
    book_t User_Manual = {"User Manual", "Library Management System", 2026, 0, NULL}; // 使用手册是0号书
    book_ptr_t User_Manual_ptr = &User_Manual;
    int next_book_id = 1;
    book_borrow_t zero = {-1, 0, NULL, "", "", "", "", ""};
    book_borrow_ptr_t zero_ptr = &zero;
    int logged_in_user_id = -1;
set_admin_password:
    printf("请设置管理员密码：");
    if (scanf("%19s", admin_ptr->password) != 1)
    {
        if (feof(stdin))
        {
            return 0;
        }
        input_discard_line();
        printf("密码输入无效，请重新输入：\n");
        goto set_admin_password;
    }
start_meun:
    while (1)
    {
        int operation;
        printf("你好！欢迎使用图书管理系统！\n");
        enum
        {
            登录 = 1,
            注册,
            退出
        };
        printf("请选择操作：1.登录 2.注册 3.退出\n");
        if (scanf("%d", &operation) != 1)
        {
            if (feof(stdin))
            {
                return 0;
            }
            input_discard_line();
            printf("输入无效，请输入 1、2 或 3。\n");
            continue;
        }
        switch (operation)
        {
        case 登录:
        {
            int login_type = user_login(admin_ptr, &next_user_id, &logged_in_user_id);
            if (login_type == 0)
            {
                goto admin_control_panel;
            }
            if (login_type == 1)
            {
                goto user_control_panel;
            }
            break;
        }
        case 注册:
            sign_up(admin_ptr, &next_user_id);
            break;
        case 退出:
            printf("感谢使用XD");
            return 0;
        default:
            printf("无效的操作。\n");
            continue;
        }
    }
admin_control_panel:
    while (1)
    {
        int operation;
        printf("你好！欢迎使用图书管理系统！\n");
        enum
        {
            图书信息显示 = 1,
            图书信息删除,
            图书信息录入,
            图书信息更新,
            退出
        };
        printf("请选择操作：1.图书信息显示 2.图书信息删除 3.图书信息录入 4.图书信息更新 5.退出\n");
        if (scanf("%d", &operation) != 1)
        {
            if (feof(stdin))
            {
                return 0;
            }
            input_discard_line();
            printf("输入无效，请输入 1、2、3、4或5。\n");
            continue;
        }
        switch (operation)
        {
        case 图书信息显示:
            book_list_review(User_Manual_ptr);
            break;
        case 图书信息删除:
        {
            int result = admin_book_delete(User_Manual_ptr, zero_ptr);
            if (result == 0)
            {
                printf("删除成功！\n");
            }
            else
            {
                printf("删除失败！\n");
            }
            break;
        }
        case 图书信息录入:
            book_list_create(User_Manual_ptr, &next_book_id);
            break;
        case 图书信息更新:
            admin_book_update(User_Manual_ptr, zero_ptr);
            break;
        case 退出:
            goto start_meun;
            break;
        default:
            printf("无效的操作。\n");
            continue;
        }
    }
user_control_panel:
    while (1)
    {
        int operation;
        printf("你好！欢迎使用图书管理系统！\n");
        enum
        {
            图书查询 = 1,
            图书借阅,
            图书归还,
            借阅查询,
            退出
        };
        printf("请选择操作：1.图书查询 2.图书借阅 3.图书归还 4.借阅查询 5.退出\n");
        if (scanf("%d", &operation) != 1)
        {
            if (feof(stdin))
            {
                return 0;
            }
            input_discard_line();
            printf("输入无效，请输入 1、2、3、4或5。\n");
            continue;
        }
        switch (operation)
        {
        case 图书查询:
            book_search(User_Manual_ptr);
            break;
        case 图书借阅:
            book_borrow(zero_ptr, User_Manual_ptr, logged_in_user_id);
            break;
        case 图书归还:
            book_return(zero_ptr, logged_in_user_id);
            break;
        case 借阅查询:
            book_borrow_review(zero_ptr, logged_in_user_id);
            break;
        case 退出:
            goto start_meun;
            break;
        default:
            printf("无效的操作。\n");
            continue;
        }
    }
}