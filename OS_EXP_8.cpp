#include <stdio.h>

int main() {
    int n, i, time = 0, remain, flag = 0, tq;
    int bt[20], rt[20]; 
    int wt = 0, tat = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for Process P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // Remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while(remain != 0) {
        for(i = 0; i < n; i++) {

            if(rt[i] == 0)   // already finished
                continue;

            if(rt[i] > tq) {
                time += tq;
                rt[i] -= tq;
            } 
            else {
                time += rt[i];
                rt[i] = 0;
                remain--;

                printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], time - bt[i], time);
                wt += time - bt[i];
                tat += time;
            }
        }
    }

    printf("\nAverage Waiting Time = %.2f\n", wt * 1.0 / n);
    printf("Average Turnaround Time = %.2f\n", tat * 1.0 / n);

    return 0;
}

