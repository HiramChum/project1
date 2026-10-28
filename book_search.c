#include <stdio.h>
#include <string.h>
#include "book.h"
#include "input_utils.h"

void book_search(book_ptr_t head)
{
    if (head == NULL)
    {
        printf("暂无图书信息。\n");
        return;
    }

    for (;;)
    {
        int operation;
        printf("请选择查询方式：1.书名 2.作者 3.年份 4.退出\n");
        if (scanf("%d", &operation) != 1)
        {
            input_discard_line();
            printf("输入无效，查询结束。\n");
            return;
        }

        if (operation == 4)
        {
            return;
        }

        if (operation == 1 || operation == 2)
        {
            char query[50];
            printf("请输入查询%s：", operation == 1 ? "书名" : "作者");
            if (scanf(" %49[^\n]", query) != 1)
            {
                printf("输入无效，查询结束。\n");
                return;
            }

            int found = 0;
            for (book_ptr_t current = head; current != NULL; current = current->next)
            {
                const char *field = operation == 1 ? current->title : current->author;
                if (strstr(field, query) != NULL)
                {
                    printf("书名：%s，作者：%s，编号：%d，年份：%d\n",
                           current->title, current->author, current->id, current->year);
                    found = 1;
                }
            }
            if (!found)
            {
                printf("没有找到符合条件的图书。\n");
            }
        }
        else if (operation == 3)
        {
            int search_year;
            printf("请输入查询年份：");
            if (scanf("%d", &search_year) != 1)
            {
                input_discard_line();
                printf("输入无效，查询结束。\n");
                return;
            }

            int found = 0;
            for (book_ptr_t current = head; current != NULL; current = current->next)
            {
                if (current->year == search_year)
                {
                    printf("书名：%s，作者：%s，编号：%d，年份：%d\n",
                           current->title, current->author, current->id, current->year);
                    found = 1;
                }
            }
            if (!found)
            {
                printf("没有找到符合条件的图书。\n");
            }
        }
        else
        {
            printf("无效的操作。\n");
        }
    }
}
