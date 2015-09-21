#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int createStack(Stack **head)
{
    *head = NULL;
    return 0;
}

int deleteStack(Stack **head)
{
    Stack *target;

    while(*head) {
        printf("[%s]->", (char *)(*head)->data);
        target = (*head)->next;
        free(*head);
        *head = target;
    }
    printf("[Null]");

    return 0;
}

int push(Stack **head, void *data)
{
    Stack *newData;

    newData = (Stack *)malloc(sizeof(Stack));

    if (!newData)
        return -1;

    newData->data = data;
    newData->next = *head;
    *head = newData;

    return 0;
}

int pop (Stack **head, void **data)
{
    Stack *target;

    if (!(target = *head)) {
        return -1;
    }

    *data = target->data;
    *head = target->next;
    free(target);

    return 0;
}
