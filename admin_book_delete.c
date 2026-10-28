#include <stdio.h>
#include "book.h"
int admin_book_delete(book_ptr_t head_ptr)
{
    printf("请输入您想删除的书籍ID\n");
    int delete_id;
    if (scanf("%d", &delete_id) == 0)
    {
        printf("输入错误，删除重试，即将退出\n");
        return 1;
    }
    book_ptr_t cerrent = head_ptr;
    while (cerrent->id != delete_id)
    {
        cerrent = cerrent->next;
    }
    book_ptr_t delete_ptr = cerrent;
    printf("是否确认删除？确认输入1，取消输入0\n");
    int choose;
    scanf("%d", &choose);
    if (choose == 1)
    {
        cerrent = head_ptr;
        while (cerrent->next = delete_ptr)
        {
            cerrent->next = delete_ptr->next;
            free(delete_ptr);
            printf("删除成功！\n");
        }
        return 0;
    }
    return 1;
}