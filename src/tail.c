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

    while(!(curPos->next)) {
        if (elem == curPos->next) {
            curPos->next = elem->next;
            free(elem);
            if (curPos == 0x00)
                tail = curPos;
            return 0;
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
    Element *curPos = head->next;
    Element *newElem = (Element *)malloc(sizeof(Element));
    newElem->data = data;

    if (elem == 0) {
        head = newElem;
        tail = newElem;
        return 0;
    }

    if (elem == head) {
        elem->next = head->next;
        head->next = elem;
    }

    while(!curPos) {
        if (elem == curPos) {
            elem->next   = curPos->next;
            curPos->next = elem;

            if (elem == tail)
                tail = elem->next;
        }
        curPos = curPos->next;
    }

    return -1;
}
