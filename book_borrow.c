#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "book_borrow.h"
#include "input_utils.h"

static int title_is_borrowed(book_borrow_ptr_t head, const char *title)
{
    for (book_borrow_ptr_t current = head; current != NULL; current = current->next_book_borrow)
    {
        char *titles[5] = {
            current->title1,
            current->title2,
            current->title3,
            current->title4,
            current->title5
        };
        int count = current->own_book;
        if (count < 0 || count > 5)
        {
            count = 5;
        }
        for (int i = 0; i < count; i++)
        {
            if (strcmp(titles[i], title) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void book_borrow(book_borrow_ptr_t borrow_head, book_ptr_t book_head, int user_id)
{
    if (borrow_head == NULL || book_head == NULL || user_id < 0)
    {
        printf("借阅信息不可用！\n");
        return;
    }

    char title[50];
    printf("请输入您要借阅的书名：\n");
    if (scanf(" %49[^\n]", title) != 1)
    {
        printf("输入无效！\n");
        return;
    }

    int book_exists = 0;
    for (book_ptr_t current = book_head; current != NULL; current = current->next)
    {
        if (strcmp(current->title, title) == 0)
        {
            book_exists = 1;
            break;
        }
    }
    if (!book_exists)
    {
        printf("馆藏中没有这本书。\n");
        return;
    }
    if (title_is_borrowed(borrow_head, title))
    {
        printf("这本书目前已被借出。\n");
        return;
    }

    book_borrow_ptr_t borrower = borrow_head;
    while (borrower != NULL && borrower->id_borrow != user_id)
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

    int choose;
    printf("确认借阅请输入1，取消请输入0：\n");
    if (scanf("%d", &choose) != 1 || choose != 1)
    {
        input_discard_line();
        printf("已取消借阅。\n");
        return;
    }

    if (borrower == NULL)
    {
        borrower = calloc(1, sizeof(*borrower));
        if (borrower == NULL)
        {
            printf("内存不足，无法借书！请联系管理员\n");
            return;
        }
        borrower->id_borrow = user_id;
        book_borrow_ptr_t current = borrow_head;
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
    strcpy(titles[borrower->own_book], title);
    borrower->own_book++;
    printf("借书完成，当前借书量为%d本。\n", borrower->own_book);
}
