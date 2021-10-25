/****************************************************
*
* Student: Paxton Proctor
* Instructor: Dr. Passos
* Class: CMPS 4103-101 Intro to Operating Systems
* Assignment: MiniProject 2
*
* Purpose: Threads
*
****************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t the_mutex;
int Total = 0;
// global array
int array[6000];
// function prototype
void *count(void *tid);

int main(void) {
    // number of threads
    pthread_t threads_id[3];
    int status, i;

    // initialization
    pthread_mutex_init(&the_mutex, 0);

    // initialization of the array
    for(int i = 0; i < 6000; i++) {
        array[i] = i + 1;
    }

    // creates threads
    for(int i = 1; i < 4; i++) {
        pthread_create(&threads_id[i], NULL, count, (void *)i);
    }

    // joins
    pthread_join( threads_id[0], NULL);
    pthread_join( threads_id[1], NULL);
    pthread_join( threads_id[2], NULL);


    printf("%d with semaphore\n", Total);
}

// function to count through threads and print total
void *count(void *tid) {

    // changes tid to a int instead of void
    int n = (int)tid;
    printf("%d\n", n);
    // should print Total for each thread
    for(int i = (n - 1) * 2000; i <= n * 2000 - 1; i++) {
        // Lock mutex
        pthread_mutex_lock(&the_mutex);
        // Total
        Total = Total + array[i];
        // Unlock mutex
        pthread_mutex_unlock(&the_mutex);
    }
    // Exit function
    pthread_exit(NULL);
}