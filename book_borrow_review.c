#include <stdio.h>
#include "book.h"
#include "book_borrow.h"
void book_borrow_review(book_borrow_ptr_t head_ptr)
{
    printf("请输入您的ID：\n");
    int user_id;
    if (scanf("%d", &user_id) != 1)
    {
        printf("输入无效，请重新输入。\n");
        return;
    }
    for (book_borrow_ptr_t current = head_ptr; current->next_book_borrow != NULL; current = current->next_book_borrow)
    {
        if (current->id_borrow == user_id)
        {
            printf("用户ID：%d，借阅书籍数量：%d，书名1：%s，书名2：%s，书名3：%s，书名4：%s，书名5：%s\n",
                   current->id_borrow, current->own_book, current->title1, current->title2, current->title3, current->title4, current->title5);
        }
    }
}