#include <stdio.h>
#include "book.h"
int admin_book_update(book_ptr_t head_ptr)
{
    printf("请输入您想更改的书籍ID\n");
    int update_id;
    if (scanf("%d", &update_id) == 0)
    {
        printf("输入错误，更改重试，即将退出\n");
        return 1;
    }
    book_ptr_t cerrent = head_ptr;
    while (cerrent->id != update_id)
    {
        cerrent = cerrent->next;
    }
    book_ptr_t update_ptr = cerrent;
    printf("是否确认更改？确认输入1，取消输入0\n");
    int choose;
    scanf("%d", &choose);
    if (choose == 1)
    {
        scanf("请输入更新书名：%49s，请输入更新作者：%49s，请输入更新年份%d",update_ptr->title,update_ptr->author);
        printf("更改成功！\n");
        return 0;
    }
    return 1;
}
