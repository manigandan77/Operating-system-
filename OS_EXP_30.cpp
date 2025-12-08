#include <stdio.h>

int main(){
    int f, n, pages[50], frame[10], used[10], faults=0, i,j;

    scanf("%d",&f);
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&pages[i]);
    for(i=0;i<f;i++) frame[i]=-1;

    for(i=0;i<n;i++){
        int found=0;
        for(j=0;j<f;j++)
            if(frame[j]==pages[i]){ found=1; used[j]=i; }

        if(!found){
            int lru=0;
            for(j=1;j<f;j++)
                if(used[j]<used[lru]) lru=j;

            frame[lru]=pages[i];
            used[lru]=i;
            faults++;
        }
    }
    printf("%d",faults);
    return 0;
}

