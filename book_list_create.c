#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book.h"

void book_list_create(book_ptr_t head, int *next_id_ptr)
{
    if (head == NULL || next_id_ptr == NULL) // 这段检查在当前调用方式下不会触发；保留它是为了防止以后其他调用者传入空指针。
    {
        return;
    }

    book_ptr_t new_book_ptr = malloc(sizeof(book_t));
    if (new_book_ptr == NULL)
    {
        printf("内存不足，无法创建新书！请联系管理员\n");
        return;
    }

    printf("请输入书名：");
    if(scanf("%49s", new_book_ptr->title) != 1)
    {
        printf("输入无效，书籍创建失败！\n");
        free(new_book_ptr);
        return;
    }           

    printf("请输入作者：");
    if(scanf("%49s", new_book_ptr->author) != 1)
    {
        printf("输入无效，书籍创建失败！\n");
        free(new_book_ptr);
        return;
    }

    printf("请输入出版年份：");
    if(scanf("%d", &new_book_ptr->year) != 1)
    {
        printf("输入无效，书籍创建失败！\n");
        free(new_book_ptr);
        return;
    }
    new_book_ptr->id = *next_id_ptr;
    new_book_ptr->next = NULL;

    book_ptr_t cerrent = head;
    if (cerrent->next != NULL)
    {
        cerrent = cerrent->next;
    }
    cerrent = new_book_ptr;
    *(next_id_ptr)++;
    printf("书籍添加完成");
}               