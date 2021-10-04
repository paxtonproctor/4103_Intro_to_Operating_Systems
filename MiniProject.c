/****************************************************
*
* Student: Paxton Proctor
* Instructor: Dr. Passos
* Class: CMPS 4103-101 Intro to Operating Systems
* Assignment: MiniProject 1
*
* Purpose: The main program will create 2 children.
* The first child will print values 1 to N/3 (integer division), the second child will print from
* N/3 +1 to 2N/3, while the main program prints the remaining values. Your mission is to
* write the program (it should be very short, less than 50 lines for sure) that creates the new
* child processes and executes the printing (screen display).
*
****************************************************/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    pid_t ChildOne, ChildTwo;

    ChildOne = fork();

    if(ChildOne == 0)//if im child one
    {
        for (int i = 1; i <= n / 3; i++)
        {
            printf(" %d", i);
        }
        // Tracking Id of proccesses mainly just trying to figure out fork
        printf("\nIm the first child and I have ID: %d\n", (int) getpid());
    }
    else
    {
        ChildTwo = fork();

        if(ChildTwo == 0)//if im child two
        {
            for (int i = (n / 3) + 1; i <= (2 * n) / 3; i++)
            {
                printf(" %d", i);
            }
            printf("\nIm the second child and I have ID: %d\n", (int) getpid());
        }
        else//if im the main program
        {
            for (int i = ((2 * n) / 3) + 1; i <= (n * 3) / 3; i++)
            {
                printf(" %d", i);
            }
            printf("\nIm the main program and I have ID: %d\n", (int) getpid());
        }
    }

    return 0;
}