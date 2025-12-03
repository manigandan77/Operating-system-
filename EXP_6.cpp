#include <stdio.h>

struct Process {
    int pid;
    int bt;     // burst time
    int at;     // arrival time
    int pr;     // priority
    int ct;     // completion time
    int wt;     // waiting time
    int tat;    // turnaround time
    int rt;     // remaining time
    int completed;
};

int main() {
    int n, time = 0, completed = 0, min_pr;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority (lower = higher priority): ");
        scanf("%d", &p[i].pr);

        p[i].rt = p[i].bt;
        p[i].completed = 0;
    }

    printf("\n\n--- Gantt Chart ---\n");
    printf("Time : Process\n");

    while (completed != n) {
        int idx = -1;
        min_pr = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0 && p[i].pr < min_pr) {
                min_pr = p[i].pr;
                idx = i;
            }
        }

        if (idx != -1) {
            printf("%d - P%d\n", time, p[idx].pid);
            p[idx].rt--;

            if (p[idx].rt == 0) {
                p[idx].ct = time + 1;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                avgWT += p[idx].wt;
                avgTAT += p[idx].tat;

                p[idx].completed = 1;
                completed++;
            }
        } 
        time++;
    }

    printf("\n\n--- Process Table ---\n");
    printf("PID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}

