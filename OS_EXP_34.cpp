#include <stdio.h>

struct node {
    int block;
    struct node *next;
};

int main(){
    int n,i;
    struct node *head=NULL,*temp,*p;

    printf("Number blocks: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Block %d: ",i);
        scanf("%d",&temp->block);
        temp->next=NULL;

        if(!head) head=temp;
        else{
            p=head;
            while(p->next) p=p->next;
            p->next=temp;
        }
    }

    p=head;
    while(p){
        printf("%d -> ",p->block);
        p=p->next;
    }
    printf("NULL");
    return 0;
}

