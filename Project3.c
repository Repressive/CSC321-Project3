#include <stdio.h>
#include <time.h>


int main()
{


    /* Declares and initialize SIZE to 1000000 */
    int SIZE = 1000000;
    int loopSIZE = 10000;
    /* Declares and initialize myArr[] to SIZE */
    int myArr[SIZE];

    /* Declares and initialize stack and pointer to sp */
    int stack[SIZE];
    int *sp;

    /* Initializes the stack */
    sp = stack;

    /* Defines how to push and pop for stack */
#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))

    int *p_array;
    p_array = (int *)malloc(sizeof(int)*1000000);      // allocate 50 ints

    /* This begins counting the time it takes via cpu clock cycle */
    clock_t begin = clock();

    /* Loops the function 1000 times */
    for(int i = 0; i < loopSIZE; i++)
    {
        myArrFunc(myArr, SIZE);
    }

    /* Ends the clock timer */
    clock_t end = clock();

    /* Calculate the time into seconds */
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time for array: %fsecs \n", time_spent);

    /* This begins counting the time it takes via cpu clock cycle */
    begin = clock();

    /* Loops the function 1000 times */
    for(int i = 0; i < loopSIZE; i++)
    {
        myStackFunc(stack, SIZE, sp);
    }

    /* Ends the clock timer */
    end = clock();

    /* Calculate the time into seconds */
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time for stack: %fsecs \n", time_spent);


    /* This begins counting the time it takes via cpu clock cycle */
    begin = clock();

    /* Loops the function 1000 times */
    for(int i = 0; i < loopSIZE; i++)
    {
        myHeapFunc(p_array, SIZE);
    }

    /* Ends the clock timer */
    end = clock();

    /* Calculate the time into seconds */
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time for heap: %fsecs \n", time_spent);
}

/* Function to declare and initialize a large array */
void myArrFunc(int myArr[], int SIZE)
{

    for(int i=0; i< SIZE; i++)
    {
        myArr[i]=i;
    }
}

void myStackFunc(int stack[], int SIZE, int *sp)
{


    for(int i = 0; i < SIZE; i++)
    {
        push(sp, i);

        /* To pop from the stack and print it out
        int  x = pop(sp);
        printf("stack: %d\n", x);
        */

    }
}

void myHeapFunc(int *p_array, int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        p_array[i] = i;
    }

}
