#include <stdio.h>
#include "book.h"
#include <string.h>

void book_search(book_ptr_t head)
{
    int operation;
    while (1)
    {
        printf("请选择您需要的查询方式：1.书名 2.作者 3.年份 4.退出");
        enum operation
        {
            书名 = 1,
            作者,
            年份,
            退出
        };
        if (scanf("%d", &operation) != 1)
        {
            printf("输入无效，请输入 1、2 或 3。\n");
            continue;
        }
        switch (operation)
        {
        case 书名:
        {
            printf("请输入查询书名：");
            char arr[50] = {0};
            if (scanf("%49s", &arr) != 1)
            {
                printf("输入无效，书籍查询失败！\n");
                return NULL;
            }
            for (book_ptr_t cerrent = head; cerrent->next != NULL; cerrent = cerrent->next)
            {
                if ((strstr((cerrent->title), arr)) != NULL)
                    printf("找到书目名字为%s，编号为：%d", cerrent->title, cerrent->id);
            }
            break;
        }
        case 作者:
        {
            printf("请输入查询作者名：");
            char arr[50] = {0};
            if (scanf("%49s", &arr) != 1)
            {
                printf("输入无效，书籍查询失败！\n");
                return NULL;
            }
            for (book_ptr_t cerrent = head; cerrent->next != NULL; cerrent = cerrent->next)
            {
                if ((strstr((cerrent->author), arr)) != NULL)
                    printf("找到书目名字为%s，编号为：%d", cerrent->title, cerrent->id);
            }
            break;
        }
        case 年份:
        {
            printf("请输入查询年份：");
            int search_year;
            if (scanf("%d", search_year) != 1)
            {
                printf("输入无效，书籍查询失败！\n");
                return NULL;
            }
            for (book_ptr_t cerrent = head; cerrent->next != NULL; cerrent = cerrent->next)
            {
                if ((cerrent->year) == search_year)
                    printf("找到书目名字为%s，编号为：%d", cerrent->title, cerrent->id);
            }
            break;
        }
        case 退出:
            return;
        default:
            printf("无效的操作。\n");
            continue;
        }
    }
}