#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "book_borrow.h"
#include "input_utils.h"

static int is_book_borrowed(book_borrow_ptr_t head, const char *title)
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

int admin_book_delete(book_ptr_t head_ptr, book_borrow_ptr_t borrow_head)
{
    if (head_ptr == NULL)
    {
        printf("图书链表不可用！\n");
        return 1;
    }

    int delete_id;
    printf("请输入您想删除的书籍ID：\n");
    if (scanf("%d", &delete_id) != 1)
    {
        input_discard_line();
        printf("输入错误，删除失败。\n");
        return 1;
    }

    book_ptr_t previous = NULL;
    book_ptr_t current = head_ptr;
    while (current != NULL && current->id != delete_id)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("没有找到该书籍。\n");
        return 1;
    }
    if (previous == NULL)
    {
        printf("使用手册不能删除。\n");
        return 1;
    }
    if (is_book_borrowed(borrow_head, current->title))
    {
        printf("该书仍在借阅中，不能删除。\n");
        return 1;
    }

    int choose;
    printf("是否确认删除？确认输入1，取消输入0\n");
    if (scanf("%d", &choose) != 1 || choose != 1)
    {
        input_discard_line();
        printf("已取消删除。\n");
        return 1;
    }

    previous->next = current->next;
    free(current);
    return 0;
}
