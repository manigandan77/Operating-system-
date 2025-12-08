#include <stdio.h>

int main(){
    int f, pages[50], frame[10], i,j,k, faults=0, n, pos=0;

    printf("Frames: ");
    scanf("%d",&f);

    printf("Pages count: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&pages[i]);
    for(i=0;i<f;i++) frame[i]=-1;

    for(i=0;i<n;i++){
        int found=0;
        for(j=0;j<f;j++)
            if(frame[j]==pages[i]) found=1;
        if(!found){
            frame[pos]=pages[i];
            pos=(pos+1)%f;
            faults++;
        }
    }
    printf("Faults: %d\n",faults);
    return 0;
}

