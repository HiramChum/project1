#include <stdio.h>
#include "book_borrow.h"

void book_borrow_review(book_borrow_ptr_t head_ptr, int user_id)
{
    if (head_ptr == NULL || user_id < 0)
    {
        printf("借阅记录不可用！\n");
        return;
    }

    for (book_borrow_ptr_t current = head_ptr;
         current != NULL;
         current = current->next_book_borrow)
    {
        if (current->id_borrow == user_id)
        {
            if (current->own_book == 0)
            {
                printf("您当前没有借阅图书。\n");
                return;
            }
            printf("用户ID：%d，借阅书籍数量：%d\n",
                   current->id_borrow, current->own_book);
            char *titles[5] = {
                current->title1,
                current->title2,
                current->title3,
                current->title4,
                current->title5
            };
            for (int i = 0; i < current->own_book && i < 5; i++)
            {
                printf("%d. %s\n", i + 1, titles[i]);
            }
            return;
        }
    }

    printf("您当前没有借阅记录。\n");
}
