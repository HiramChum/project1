#include <stdio.h>
#include "book.h"
void book_list_review(book_ptr_t head_ptr)
{
    if (head_ptr == NULL)
    {
        printf("暂无图书信息。\n");
        return;
    }

    for (book_ptr_t current = head_ptr; current != NULL; current = current->next)
    {
        printf("书名：%s，作者：%s，编号：%d，年份：%d\n",
               current->title, current->author, current->id, current->year);
    }
}