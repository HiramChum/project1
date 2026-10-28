#include <stdio.h>
#include "book.h"
#include "book_borrow.h"

int admin_book_delete(book_ptr_t head_ptr, book_borrow_ptr_t borrow_head);
int book_list_create(book_ptr_t head_ptr, int *next_book_id_ptr);
int admin_book_update(book_ptr_t head_ptr, book_borrow_ptr_t borrow_head);
void book_list_review(book_ptr_t head_ptr);

void function_admin(book_ptr_t book_head,
                    int *next_book_id_ptr,
                    book_borrow_ptr_t borrow_head)
{
    if (book_head == NULL || next_book_id_ptr == NULL)
    {
        printf("管理员功能不可用！\n");
        return;
    }

    for (;;)
    {
        int choice;
        printf("1.图书信息显示\n");
        printf("2.图书信息删除\n");
        printf("3.图书信息录入\n");
        printf("4.图书信息更新\n");
        printf("5.返回\n");
        printf("请选择功能：\n");

        if (scanf("%d", &choice) != 1)
        {
            printf("输入无效，返回管理员菜单。\n");
            return;
        }

        switch (choice)
        {
        case 1:
            book_list_review(book_head);
            break;
        case 2:
            if (admin_book_delete(book_head, borrow_head) == 0)
            {
                printf("删除成功！\n");
            }
            else
            {
                printf("删除失败！\n");
            }
            break;
        case 3:
            book_list_create(book_head, next_book_id_ptr);
            break;
        case 4:
            admin_book_update(book_head, borrow_head);
            break;
        case 5:
            return;
        default:
            printf("无效选择，请重新输入。\n");
            break;
        }
    }
}
