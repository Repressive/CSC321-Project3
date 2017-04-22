/*
* @Author: Jimmy Tun
* @Author: Mark Medina
* @Author: Ryan Downs
* CSC321 Project 3
*
* This program uses the cpu clock cycle to keep track of the time it takes for each function to loop.
* Everytime the function is called it overwrites the begin clock and end clock tracker variables.
* The program prints the time it takes for each function to complete it's 1000 loops.
*/
#include <stdio.h>
#include <time.h>


int main()
{


    /* Declares and initialize SIZE to 1000000 and loopSIZE to 1000*/
    int SIZE = 1000000;
    int loopSIZE = 1000;

    /* Declares and initialize static myArr[] to SIZE */
    int myArr[SIZE];

    /* Declares and initialize stack[SIZE] and pointer to sp */
    int stack[SIZE];
    int *sp;

    /* Initializes the stack */
    sp = stack;

    /* Defines how to push and pop for stack */
#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))

    /* Declares and initalize the heap */
    int *heap;
    heap = (int *)malloc(sizeof(int)*1000000);

/*===============================================================================================================*/
    /* Begins tracking the cpu clock cycle to record time for array data segment function */
    clock_t begin = clock();

    /* Loops the function 1000 times */
    for(int i = 0; i < loopSIZE; i++) {
        /* Passes data the array function */
        myArrFunc(myArr, SIZE);
    }

    /* Ends the cpu clock timer */
    clock_t end = clock();

    /* Calculate the time into seconds */
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    /* Prints the execution time */
    printf("Execution Time for array: %fsecs \n", time_spent);

/*===============================================================================================================*/
    /* Begins tracking the cpu clock cycle to record time for stack function*/
    begin = clock();

    /* Loops the function 1000 times */
    for(int i = 0; i < loopSIZE; i++) {
        /* Passes data the stack function */
        myStackFunc(stack, SIZE, sp);
    }

    /* Ends the  cpu clock timer */
    end = clock();

    /* Calculate the time into seconds */
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    /* Prints the execution time */
    printf("Execution Time for stack: %fsecs \n", time_spent);

/*===============================================================================================================*/
    /* Begins tracking the cpu clock cycle to record time for heap function */
    begin = clock();

    /* Loops the function 1000 times */
    for(int i = 0; i < loopSIZE; i++) {
        /* Passes data the heap function */
        myHeapFunc(heap, SIZE);
    }

    /* Ends the cpu clock timer */
    end = clock();

    /* Calculate the time into seconds */
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    /* Prints the execution time */
    printf("Execution Time for heap: %fsecs \n", time_spent);
}

/*===============================================================================================================*/
/* Function to use the passed data to fill the array*/
void myArrFunc(int myArr[], int SIZE) {
    for(int i=0; i< SIZE; i++) {
        myArr[i]=i;
    }
}

/*===============================================================================================================*/
/* Function to use the passed data to fill the stack */
void myStackFunc(int stack[], int SIZE, int *sp) {
    for(int i = 0; i < SIZE; i++) {
        push(sp, i);

        /* To pop from the stack and print it out
        int  x = pop(sp);
        printf("stack: %d\n", x);
        */

    }
}

/*===============================================================================================================*/
/* Function to use the passed data to fill the heap */
void myHeapFunc(int *heap, int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        heap[i] = i;
    }

}
