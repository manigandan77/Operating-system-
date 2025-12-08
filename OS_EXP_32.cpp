#include <stdio.h>

int main(){
    int start, len, i;
    printf("Start block: ");
    scanf("%d",&start);
    printf("Length: ");
    scanf("%d",&len);

    printf("Allocated blocks:\n");
    for(i=start;i<start+len;i++)
        printf("%d ",i);
    return 0;
}

