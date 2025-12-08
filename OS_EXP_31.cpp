#include <stdio.h>

int main(){
    int f,n,pages[50],frame[10],i,j,k,faults=0;

    scanf("%d",&f);
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&pages[i]);
    for(i=0;i<f;i++) frame[i]=-1;

    for(i=0;i<n;i++){
        int found=0;
        for(j=0;j<f;j++)
            if(frame[j]==pages[i]) found=1;

        if(!found){
            int far=-1,pos=-1;
            for(j=0;j<f;j++){
                int next=-1;
                for(k=i+1;k<n;k++)
                    if(frame[j]==pages[k]){ next=k; break; }

                if(next==-1){ pos=j; break; }
                if(next>far){ far=next; pos=j; }
            }
            frame[pos]=pages[i];
            faults++;
        }
    }
    printf("%d",faults);
    return 0;
}

