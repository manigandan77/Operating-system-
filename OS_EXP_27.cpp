#include <stdio.h>

int mutex=1, full=0, empty=5, x=0;

int wait(int s){ return --s; }
int signal(int s){ return ++s; }

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Produced %d\n",x);
    mutex = signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumed %d\n",x);
    x--;
    mutex = signal(mutex);
}

int main(){
    int ch;
    while(1){
        printf("1.P 2.C 3.Exit: ");
        scanf("%d",&ch);
        if(ch==1){
            if((mutex==1)&&(empty!=0)) producer();
            else printf("Buffer full\n");
        } else if(ch==2){
            if((mutex==1)&&(full!=0)) consumer();
            else printf("Buffer empty\n");
        } else return 0;
    }
}

