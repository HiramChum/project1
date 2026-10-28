#include <stdio.h>
#include <string.h>
#include "book_borrow.h"
#include "input_utils.h"

void book_return(book_borrow_ptr_t book_borrow_head, int user_id)
{
    if (book_borrow_head == NULL || user_id < 0)
    {
        printf("当前没有借阅记录！\n");
        return;
    }

    book_borrow_ptr_t borrower = book_borrow_head;
    while (borrower != NULL && borrower->id_borrow != user_id)
    {
        borrower = borrower->next_book_borrow;
    }
    if (borrower == NULL || borrower->own_book <= 0 || borrower->own_book > 5)
    {
        printf("您当前没有借阅记录！\n");
        return;
    }

    char title[50];
    printf("请输入您要归还的书名：\n");
    if (scanf(" %49[^\n]", title) != 1)
    {
        printf("输入无效！\n");
        return;
    }

    char *titles[5] = {
        borrower->title1,
        borrower->title2,
        borrower->title3,
        borrower->title4,
        borrower->title5
    };

    int title_index = -1;
    for (int i = 0; i < borrower->own_book; i++)
    {
        if (strcmp(titles[i], title) == 0)
        {
            title_index = i;
            break;
        }
    }
    if (title_index == -1)
    {
        printf("您没有借阅这本书！\n");
        return;
    }

    int confirmation;
    printf("确认归还请输入1，取消请输入0：\n");
    if (scanf("%d", &confirmation) != 1 || confirmation != 1)
    {
        input_discard_line();
        printf("已取消归还。\n");
        return;
    }

    for (int i = title_index; i < borrower->own_book - 1; i++)
    {
        strcpy(titles[i], titles[i + 1]);
    }
    titles[borrower->own_book - 1][0] = '\0';
    borrower->own_book--;

    printf("归还成功，当前借书量为%d本。\n", borrower->own_book);
}
