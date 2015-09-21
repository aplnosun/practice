#include <stdio.h>
#include <stdlib.h>
#include "test.h"

/***<VARIABLES>****************************************************************/
struct  Element *head;
struct  Element *tail;

int delete(Element *elem)
{
    struct Element *curPos;

    if (head == 0) {
        printf("List is NULL!!!\n");
        return -1;
    }

    if (elem == head) {
        head = elem->next;
        free(elem);
        return 0;
    }

    curPos = head;

    while(curPos->next) {
        if (elem == curPos->next) {
            curPos->next = elem->next;
            free(elem);
            break;
        }
        else {
            curPos = curPos->next;
        }

        if (elem == tail) {
            tail = curPos;
            free(elem);
            break;
        }
    }

    return 0;
}

int insertAfter(Element *elem, int data)
{
    if (head == 0) {
        head = elem;
        elem->data = data;
    }

    return 0;
}
