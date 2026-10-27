#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sign_up(User_Ptr *head, int *next_id)
{
    if (head == NULL || next_id == NULL)
    {
        return;
    }

    User_Ptr new_user = malloc(sizeof(User_t));
    if (new_user == NULL)
    {
        printf("内存不足，注册失败！请联系管理员\n");
        return;
    }

    printf("请输入用户名：");
    if (scanf("%19s", new_user->name) != 1)
    {
        printf("输入无效，注册失败！\n");        
        free(new_user);
        return;
    }

    for (User_Ptr current = *head; current != NULL; current = current->next)
    {
        if (strcmp(current->name, new_user->name) == 0)
        {
            printf("用户名已存在，注册失败！\n");
            free(new_user);
            return;
        }
    }

    printf("请输入密码：");
    if (scanf("%19s", new_user->password) != 1)
    {
        printf("输入无效，注册失败！\n");
        free(new_user);
        return;
    }

    new_user->id = *next_id;
    new_user->role = 1;
    new_user->next = NULL;

    User_Ptr tail = *head;
    if (tail == NULL)
    {
        *head = new_user;
    }
    else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new_user;
    }

    (*next_id)++;
    printf("注册成功！你的用户 ID 是：%d\n", new_user->id);
}
