#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "input_utils.h"

int book_list_create(book_ptr_t head_ptr, int *next_book_id_ptr)
{
    if (head_ptr == NULL || next_book_id_ptr == NULL)
    {
        printf("图书链表不可用！\n");
        return 1;
    }

    book_ptr_t new_book_ptr = malloc(sizeof(*new_book_ptr));
    if (new_book_ptr == NULL)
    {
        printf("内存不足，无法创建新书！请联系管理员\n");
        return 1;
    }

    printf("请输入书名：");
    if (scanf(" %49[^\n]", new_book_ptr->title) != 1)
    {
        printf("输入无效，书籍创建失败！\n");
        free(new_book_ptr);
        return 1;
    }

    printf("请输入作者：");
    if (scanf(" %49[^\n]", new_book_ptr->author) != 1)
    {
        printf("输入无效，书籍创建失败！\n");
        free(new_book_ptr);
        return 1;
    }

    printf("请输入出版年份：");
    if (scanf("%d", &new_book_ptr->year) != 1)
    {
        input_discard_line();
        printf("输入无效，书籍创建失败！\n");
        free(new_book_ptr);
        return 1;
    }

    for (book_ptr_t current = head_ptr; current != NULL; current = current->next)
    {
        if (strcmp(current->title, new_book_ptr->title) == 0)
        {
            printf("馆藏中已存在同名图书。\n");
            free(new_book_ptr);
            return 1;
        }
    }

    int choose;
    printf("是否确认添加？确认输入1，取消输入0\n");
    if (scanf("%d", &choose) != 1 || choose != 1)
    {
        input_discard_line();
        printf("已取消添加。\n");
        free(new_book_ptr);
        return 1;
    }

    new_book_ptr->id = *next_book_id_ptr;
    new_book_ptr->next = NULL;

    book_ptr_t current = head_ptr;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_book_ptr;

    (*next_book_id_ptr)++;
    printf("书籍添加完成，编号为%d。\n", new_book_ptr->id);
    return 0;
}
