#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, head, req[50], i, sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&req[i]);
    scanf("%d",&head);

    for(i=0;i<n;i++){
        sum += abs(req[i]-head);
        head=req[i];
    }

    printf("%d",sum);
    return 0;
}

