#include <stdio.h>
#include "book.h"
void book_list_review(book_ptr_t head_ptr)
{
    for (book_ptr_t cerrent = head_ptr; cerrent->next != NULL; cerrent = cerrent->next)
    {
        printf("书名：%s，作者：%s，编号：%d，年份：%d\n",cerrent->title,cerrent->author,cerrent->id,cerrent->year);
    }
}