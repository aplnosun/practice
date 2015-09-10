/******************************************************************************
 *  Project name  : Programming interview solution
 *  Project object: programming practice
 *  Source file   : test.c
 ******************************************************************************/

/***<HEADER FILES>*************************************************************/
#include "test.h"

/***<DEFINE CONSTANTS>*********************************************************/
#define SZ_MAX      150

/******************************************************************************
 * Function     : main
 * Description  :
 * Input param  : argc - number of arguments
 *                argv - arguments
 * Output param :
 * Return value : SUCCESS - 0
 *                FAIL    - none zero
 ******************************************************************************/
int main(int argc, char *argv[])
{
    char input[2]={0,};

    printf("00000 test.\n");
    printf("argc[%d], argv[%s]\n", argc, *argv);

    if (argc != 1) {
        printf("Usage: test\n");
        return -1;
    }

    while(1) {
        printf("************************\n");
        printf("*       1. stack       *\n");
        printf("*       2. tail        *\n");
        printf("************************\n");
        printf("select number(q:quit):  \n");

        scanf("%s", input);

        if (input[0] == 'q' ||  input[0] == 'Q') {
            printf("bye!!!\n");
            break;
        }

        switch(input[0]) {
            case '1':
                testStack();
                break;
            case '2':
                testTail();
                break;
            default:
                printf("wrong input data!!!\n\n");
                wait();
                break;
        }
    }

    return 0;
}

int testStack()
{
    char input[2]={0,};

    printf("<<<<< Stack >>>>>\n");

    while(1) {
        printf("************************\n");
        printf("*       1. push        *\n");
        printf("*       2. pop         *\n");
        printf("*       3. view        *\n");
        printf("************************\n");
        printf("select number(q:quit): ");

        scanf("%s", input);

        if (input[0] == 'q' ||  input[0] == 'Q') {
            printf("bye!!!\n");
            break;
        }

        switch(input[0]) {
            case '1':
                printf("Enter the push data: ");
                scanf("%s", input);
                break;
            case '2':
                printf("pop: ");
                wait();
                break;
            case '3':
                printf("view: ");
                scanf("%s", input);
                break;
            default:
                printf("wrong input data!!!\n");
                wait();
                break;
        }
    }

    return 0;
}

int testTail()
{
    printf("<<<<< Tail >>>>>\n");
    wait();

    return 0;
}

void wait(void)
{
    printf("Press any key to continue . . .");
    getchar();
    puts("");
}
