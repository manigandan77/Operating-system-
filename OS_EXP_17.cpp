#include<stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10], safeSeq[10];

    printf("Enter no. of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter max matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter available: ");
    for(j=0;j<m;j++)
        scanf("%d",&avail[j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i=0;i<n;i++) finish[i]=0;
    int count=0;

    while(count < n) {
        int flag=0;
        for(i=0;i<n;i++) {
            if(!finish[i]) {
                for(j=0;j<m;j++)
                    if(need[i][j] > avail[j]) break;

                if(j==m) {
                    for(k=0;k<m;k++)
                        avail[k] += alloc[i][k];
                    finish[i]=1;
                    safeSeq[count++] = i;
                    flag=1;
                }
            }
        }
        if(!flag) { 
            printf("System in unsafe state!\n"); 
            return 0;
        }
    }

    printf("Safe sequence: ");
    for(i=0;i<n;i++) printf("P%d ", safeSeq[i]);
    return 0;
}

