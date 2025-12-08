#include<stdio.h>
#include<pthread.h>

int counter=0;
pthread_mutex_t lock;

void* increment(void* arg) {
    pthread_mutex_lock(&lock);
    counter++;
    printf("Thread %d incremented counter to %d\n", 
            (int)arg, counter);
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, (void*)1);
    pthread_create(&t2, NULL, increment, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}

