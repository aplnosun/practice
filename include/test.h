/***<HEADER FILES>*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <locale.h>
#include <iconv.h>

/***<VARIABLES>****************************************************************/

/***<STRUCTURE>****************************************************************/
typedef struct Stack{
    struct Stack	*next;
    void	*data;
}Stack;

typedef struct Element{
    struct Element *next;
    int     data;
}Element;

/***<FUNCTION PROTOTYPE>*******************************************************/
/********** stack.c **********/
int createStack(Stack **head);
int deleteStack(Stack **head);
int push(Stack **head, void *data);
int pop (Stack **head, void **data);

/********** tail.c **********/
int delete(Element *elem);
int insertAfter(Element *elem, int data);
