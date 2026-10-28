#include <stdio.h>
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

int admin_book_update(book_ptr_t head_ptr, book_borrow_ptr_t borrow_head)
{
    if (head_ptr == NULL)
    {
        printf("图书链表不可用！\n");
        return 1;
    }

    int update_id;
    printf("请输入您想更改的书籍ID：\n");
    if (scanf("%d", &update_id) != 1)
    {
        input_discard_line();
        printf("输入错误，更新失败。\n");
        return 1;
    }

    book_ptr_t current = head_ptr;
    while (current != NULL && current->id != update_id)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("没有找到该书籍。\n");
        return 1;
    }

    char title[50];
    char author[50];
    int year;
    printf("请输入更新书名：");
    if (scanf(" %49[^\n]", title) != 1)
    {
        printf("输入无效，更新失败。\n");
        return 1;
    }
    printf("请输入更新作者：");
    if (scanf(" %49[^\n]", author) != 1)
    {
        printf("输入无效，更新失败。\n");
        return 1;
    }
    printf("请输入更新年份：");
    if (scanf("%d", &year) != 1)
    {
        input_discard_line();
        printf("输入无效，更新失败。\n");
        return 1;
    }

    if (strcmp(current->title, title) != 0 &&
        is_book_borrowed(borrow_head, current->title))
    {
        printf("该书仍在借阅中，不能修改书名。\n");
        return 1;
    }

    for (book_ptr_t book = head_ptr; book != NULL; book = book->next)
    {
        if (book != current && strcmp(book->title, title) == 0)
        {
            printf("馆藏中已存在同名图书，不能更新。\n");
            return 1;
        }
    }

    int choose;
    printf("是否确认更改？确认输入1，取消输入0\n");
    if (scanf("%d", &choose) != 1 || choose != 1)
    {
        input_discard_line();
        printf("已取消更改。\n");
        return 1;
    }

    strcpy(current->title, title);
    strcpy(current->author, author);
    current->year = year;
    printf("更改成功！\n");
    return 0;
}
