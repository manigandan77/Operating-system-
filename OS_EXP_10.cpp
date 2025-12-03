#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Message {
    int available;       // 0 = empty, 1 = message present
    char text[MAX];
};

// simulate message queue
struct Message queue;

void sender() {
    strcpy(queue.text, "Hello from Sender!");
    queue.available = 1;  // Mark message available
    printf("Sender: Message Sent -> %s\n", queue.text);
}

void receiver() {
    if (queue.available == 1) {
        printf("Receiver: Message Received -> %s\n", queue.text);
        queue.available = 0;  // Mark queue empty
    } else {
        printf("Receiver: No message found!\n");
    }
}

int main() {
    queue.available = 0;

    printf("----- Message Queue Simulation -----\n");

    sender();
    receiver();

    return 0;
}

