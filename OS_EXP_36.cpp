#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, head, i, j, disk;
    int arr[50];

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&head);
    scanf("%d",&disk);

    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }

    int sum=0, pos=0;
    for(i=0;i<n;i++)
        if(head<arr[i]){ pos=i; break; }

    for(i=pos;i<n;i++){
        sum+=abs(head-arr[i]); head=arr[i];
    }
    sum+=abs(head-disk); head=disk;

    for(i=pos-1;i>=0;i--){
        sum+=abs(head-arr[i]); head=arr[i];
    }

    printf("%d",sum);
    return 0;
}

