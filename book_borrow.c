#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "book_borrow.h"

void book_borrow(book_borrow_ptr_t head)
{
    if (head == NULL)
    {
        printf("借阅记录不可用！\n");
        return;
    }

    int user_id;
    printf("请输入您的ID：\n");
    if (scanf("%d", &user_id) != 1)
    {
        printf("输入无效！\n");
        return;
    }

    char title[50];
    printf("请输入您要借阅的书名：\n");
    if (scanf(" %49[^\n]", title) != 1)
    {
        printf("输入无效！\n");
        return;
    }

    book_borrow_ptr_t borrower = head;
    while (borrower != NULL && borrower->id_borow != user_id)
    {
        borrower = borrower->next_book_borrow;
    }

    if (borrower != NULL && (borrower->own_book < 0 || borrower->own_book > 5))
    {
        printf("借阅记录异常，无法借书！\n");
        return;
    }
    if (borrower != NULL && borrower->own_book == 5)
    {
        printf("每位用户最多只能借阅5本书！\n");
        return;
    }

    printf("是否确认更改？确认输入1，取消输入0\n");
    int choose;
    if (scanf("%d", &choose) != 1)
    {
        printf("输入无效！\n");
        return;
    }
    if (choose == 1)
    {
        if (borrower == NULL)
        {
            borrower = calloc(1, sizeof(book_borrow_t));
            if (borrower == NULL)
            {
                printf("内存不足，无法借书！请联系管理员\n");
                return;
            }
            borrower->id_borow = user_id;
            book_borrow_ptr_t current = head;
            while (current->next_book_borrow != NULL)
            {
                current = current->next_book_borrow;
            }
            current->next_book_borrow = borrower;
        }

        char *titles[5] = {
            borrower->title1,
            borrower->title2,
            borrower->title3,
            borrower->title4,
            borrower->title5
        };
        for (int i = 0; i < borrower->own_book; i++)
        {
            if (strcmp(titles[i], title) == 0)
            {
                printf("您已经借阅了这本书！\n");
                return;
            }
        }

        strcpy(titles[borrower->own_book], title);
        borrower->own_book++;
        printf("借书完成，当前借书量为%d本。\n", borrower->own_book);
        return;
    }
    printf("借阅取消\n");
}
