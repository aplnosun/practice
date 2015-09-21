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
    struct Stack *next;
    void         *data;
}STACK;

/***<FUNCTION PROTOTYPE>*******************************************************/
/********** stack.c **********/
int createStack(STACK **head);
int deleteStack(STACK **head);
int push(STACK **head, void *data);
int pop (STACK **head, void **data);
