/******************************************************************************
 *  Project name  : Programming interview solution
 *  Project object: programming practice
 *  Source file   : test.c
 ******************************************************************************/

/***<HEADER FILES>*************************************************************/
#include "test.h"

/***<DEFINE CONSTANTS>*********************************************************/
#define SZ_MAX      150

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
	int input = 0;

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
        printf("select number(0:quit): ");

        scanf("%d", &input);

        if (input == 0) {
            printf("bye!!!");
            break;
        }

        switch(input) {
            case 1:
                if (testStack()) {
					printf("Error!!!");
					wait();
					return -1;
				}
                break;
            case 2:
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
	STACK *head;
	int input = 0;
	int output = 0;

	printf("\n<<<<< Stack >>>>>\n");

	createStack(&head);

    while(1) {
        printf("************************\n");
        printf("*       1. push        *\n");
        printf("*       2. pop         *\n");
        printf("*       3. delete      *\n");
        printf("************************\n");
        printf("select number(0:quit): ");

        scanf("%d", &input);

        if (input == 0) {
			printf("\n");
            break;
        }

        switch(input) {
            case 1:
                printf("Enter the push data: ");
                scanf("%d", &input);
				if (push(&head, input)) {
					return -1;
				}
                break;
            case 2:
				if (pop(&head, &output)) {
					printf("data is none!!\n");
					break;
				}
                printf("pop data: %d\n", output);
                break;
            case 3:
                printf("view: ");
				if (deleteStack(&head)) {
					return -1;
				}
                printf("\n");
                break;
            default:
                printf("wrong input data!!!\n");
                wait();
                break;
        }
		printf("\n<<<<< Stack >>>>>\n");
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
    printf("\nPress any key to continue . . .");
    getchar();
    puts("");
}
