#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t forks[NUM_PHILOSOPHERS]; 
pthread_t philosophers[NUM_PHILOSOPHERS];

// Function for each philosopher
void* dine(void* num) {
    int id = *(int*)num;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    while(1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        // Pick left fork
        sem_wait(&forks[left]);
        printf("Philosopher %d picked LEFT fork %d\n", id, left);

        // Pick right fork
        sem_wait(&forks[right]);
        printf("Philosopher %d picked RIGHT fork %d\n", id, right);

        printf("Philosopher %d is EATING ???\n", id);
        sleep(2);

        // Put down forks
        sem_post(&forks[left]);
        sem_post(&forks[right]);

        printf("Philosopher %d finished eating & put down forks\n", id);
    }
}

int main() {
    int i;
    int philosopher_ids[NUM_PHILOSOPHERS];

    // Initialize semaphores (forks)
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, dine, &philosopher_ids[i]);
    }

    // Join threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}

