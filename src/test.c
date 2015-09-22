/******************************************************************************
 *  Project name  : Programming interview solution
 *  Project object: programming practice
 *  Source file   : test.c
 ******************************************************************************/

/***<HEADER FILES>*************************************************************/
#include "test.h"

/***<DEFINE CONSTANTS>*********************************************************/
#define SZ_MAX      150

/***<VARIABLES>****************************************************************/

/***<FUNCTION>****************************************************************/
int testStack();
int testTail();
void wait(void);

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
    char input[10] = {0,};

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
        printf("select number(q:quit): ");

        scanf("%s", input);
		input[10] = 0x00;

        if (input[0] == 'q' || input[0] == 'Q') {
            printf("bye!!!");
            break;
        }

        switch(input[0]) {
            case '1':
                if (testStack()) {
                    printf("Error!!!");
                    wait();
                    return -1;
                }
                break;
            case '2':
                if (testTail()) {
                    printf("Error!!!");
                    wait();
                    return -1;
                }
                break;
            default:
                printf("wrong input data!!!\n");
                wait();
                break;
        }
    }

    return 0;
}

int testStack()
{
    Stack *head;
    char  input[10] = {0,};

    char *testInput;
    char *testOutput;

    printf("\n<<<<< Stack >>>>>\n");

    createStack(&head);

    while(1) {
        printf("************************\n");
        printf("*       1. push        *\n");
        printf("*       2. pop         *\n");
        printf("*       3. delete      *\n");
        printf("************************\n");
        printf("select number(q:quit): ");

        scanf("%s", input);
		input[10] = 0x00;

        if (input[0] == 'q' || input[0] == 'Q') {
            printf("\n");
            break;
        }

        switch(input[0]) {
            case '1':
                testInput = (char *)malloc(sizeof(char)*100);
                memset(testInput, 0x00, sizeof(sizeof(char)*100));

                printf("Enter the push data: ");
                scanf("%s", testInput);
				testInput[100] = 0x00;
                if (push(&head, testInput)) {
                    return -1;
                }
                break;
            case '2':
                testOutput = (char *)calloc(100, sizeof(char));
                if (pop(&head, (void *)&testOutput)) {
                    printf("data is none!!\n");
                    break;
                }
                printf("pop data: %s\n", testOutput);
                break;
            case '3':
                printf("view: ");
                if (deleteStack(&head)) {
                    return -1;
                }
                printf("\n");
                break;
            default:
                printf("wrong testInput data!!!\n");
                wait();
                break;
        }
        printf("\n<<<<< Stack >>>>>\n");
    }

    return 0;
}

int testTail()
{
    Element *elem;
	extern Element *head;

    char  input[10] = {0,};
    int testInput;

    printf("\n<<<<< Tail >>>>>\n");

    while(1) {
        printf("****************************\n");
        printf("*       1. insertAfter     *\n");
        printf("*       2. delete          *\n");
        printf("****************************\n");
        printf("select number(q:quit): ");

        scanf("%s", input);
		input[10] = 0x00;

        if (input[0] == 'q' || input[0] == 'Q') {
            printf("\n");
            break;
        }

        switch(input[0]) {
            case '1':
				elem = head;
				while(!elem) {
					printf("[%d]->", (int)elem);
					elem = elem->next;
				}
				printf("[Null]\n");

                printf("Enter the target address: ");
                scanf("%d", (int *)elem);
                printf("Enter the integer data: ");
                scanf("%d", &testInput);
                if (insertAfter(elem, testInput)) {
                    wait();
                    return -1;
                }
                break;
            case '2':
                elem = (Element *)malloc(sizeof(char)*100);
                memset(elem, 0x00, sizeof(sizeof(char)*100));
                printf("Target address: ");
                scanf("%s", (char *)elem);
                if (delete(elem)) {
                    return -1;
                }
                printf("\n");
                break;
            default:
                printf("wrong testInput data!!!\n");
                wait();
                break;
        }
        printf("\n<<<<< Tail >>>>>\n");
    }
    return 0;
}

void wait(void)
{
    printf("\nPress any key to continue . . .");
    getchar();
    puts("");
}
