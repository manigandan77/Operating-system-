#include <stdio.h>

struct Process {
    int pid;          // Process ID
    int at;           // Arrival Time
    int bt;           // Burst Time
    int ct;           // Completion Time
    int wt;           // Waiting Time
    int tat;          // Turnaround Time
    int completed;    // Check if completed
};

int main() {
    int n, time = 0, completed = 0;

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

        p[i].completed = 0;
    }

    printf("\n--- Gantt Chart Execution ---\n");

    while (completed != n) {
        int idx = -1;
        int minBT = 9999;

        // Select process with smallest Burst Time that has arrived  
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0 && p[i].bt < minBT) {
                minBT = p[i].bt;
                idx = i;
            }
        }

        if (idx != -1) {
            printf("%d -> P%d\n", time, p[idx].pid);

            time += p[idx].bt;   // Run process fully (Non-preemptive)
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            p[idx].completed = 1;
            completed++;
        } else {
            time++; // If no process has arrived, increment time
        }
    }

    // Display results
    printf("\n--- Process Table ---\n");
    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");

    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].wt, p[i].tat);

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}

