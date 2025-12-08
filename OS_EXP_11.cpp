#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>   // For Sleep()

// Thread function 1
void* threadFunc1(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 1 is running... (%d)\n", i+1);
        Sleep(500); // Sleep for 0.5 seconds
    }
    return NULL;
}

// Thread function 2
void* threadFunc2(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 2 is running... (%d)\n", i+1);
        Sleep(500);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Creating two threads
    pthread_create(&t1, NULL, threadFunc1, NULL);
    pthread_create(&t2, NULL, threadFunc2, NULL);

    // Wait for threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have finished execution.\n");

    return 0;
}

