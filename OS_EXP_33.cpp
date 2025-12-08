#include <stdio.h>

int main(){
    int index[20], n, i;

    printf("Number of blocks: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Block %d: ",i);
        scanf("%d",&index[i]);
    }

    printf("File blocks: ");
    for(i=0;i<n;i++) printf("%d ",index[i]);

    return 0;
}

