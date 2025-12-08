#include <stdio.h>
#include <pthread.h>

void* func(void* arg){
    printf("Thread running...\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1,NULL,func,NULL);
    pthread_join(t1,NULL);

    pthread_create(&t2,NULL,func,NULL);

    if(pthread_equal(t1,t2))
        printf("Equal\n");
    else
        printf("Not equal\n");

    pthread_exit(NULL);
    return 0;
}

