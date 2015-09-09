#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    struct Stack *next;
    void *data;
}STACK;

int createStack(STACK **head);
int deleteStack(STACK **head);
int push(STACK **head, void *data);
int pop (STACK **head, void **data);

int createStack(STACK **head)
{
    *head = NULL;
	return 0;
}

int deleteStack(STACK **head)
{
	STACK *target;

	while(*head) {
		printf("Stack data is [%d]\n", (int)(*head)->data);
		target = (*head)->next;
		free(*head);
		*head = target;
	}

	return 0;
}

int push(STACK **head, void *data)
{
	STACK *newData;

    newData = (STACK *)malloc(sizeof(STACK));

	if (!newData)
		return -1;

	newData->data = data;
	newData->next = *head;
	*head = newData;

	return 0;
}

int pop (STACK **head, void **data)
{
	STACK *target;

	if (!(target = *head))
		return -1;

	*data = target->data;
	*head = target->next;
	free(target);

	return 0;
}

