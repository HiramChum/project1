#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sign_up(user_ptr_t head, int *next_id)
{
    if (head == NULL || next_id == NULL) // 这段检查在当前调用方式下不会触发；保留它是为了防止以后其他调用者传入空指针。
    {
        return;
    }

    user_ptr_t new_user_ptr = malloc(sizeof(user_t));
    if (new_user_ptr == NULL)
    {
        printf("内存不足，注册失败！请联系管理员\n");
        return;
    }
user_name_input:
    printf("请输入用户名,输入#退出：");
    if (scanf("%19s", new_user_ptr->name) != 1)
    {
        if (feof(stdin) || ferror(stdin))
        {
            free(new_user_ptr);
            printf("输入结束，注册取消。\n");
            return;
        }
        printf("输入无效，请重新输入：\n");
        goto user_name_input;
    }
    if (strcmp(new_user_ptr->name, "#") == 0)
    {
        free(new_user_ptr);
        return;
    }
    for (user_ptr_t current = head; current != NULL; current = current->next)
    {
        if (strcmp(current->name, new_user_ptr->name) == 0)
        {
            printf("用户名已存在，请重新输入：\n");
            goto user_name_input;
        }
    }

password_input:
    printf("请输入密码，输入#退出：");
    if (scanf("%19s", new_user_ptr->password) != 1)
    {
        if (feof(stdin) || ferror(stdin))
        {
            free(new_user_ptr);
            printf("输入结束，注册取消。\n");
            return;
        }
        printf("输入无效，请重新输入：\n");
        goto password_input;
    }
    if (strcmp(new_user_ptr->password, "#") == 0)
    {
        free(new_user_ptr);
        return;
    }

    new_user_ptr->id = *next_id;
    new_user_ptr->next = NULL;

    user_ptr_t current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_user_ptr;

    (*next_id)++;
    printf("注册成功！你的用户 ID 是：%d\n", new_user_ptr->id);
}
