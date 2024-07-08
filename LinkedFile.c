#include<stdio.h>
#include<stdlib.h>

struct block{
    int bno;
    struct block* next;
};

void alloc(int bno, struct block** head){
    struct block* curr;
    struct block* b=(struct block*)malloc(sizeof(struct block));
    b->bno=bno;
    b->next=NULL;
    if(*head==NULL){
        *head=b;
    }
    else{
        curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=b;
    }
}

void main(){
    int bno,num,fno,check[10],ind=0,flag;
    struct block* files[10];
    
    printf("\nenter number of files: ");
    scanf("%d",&fno);
    for(int f=0;f<fno;f++){
        struct block* curr;
        files[f]=NULL;
        printf("\nenter number of blocks needed for file %d: ",f+1);
        scanf("%d",&num);
        for(int i=0;i<num;i++){
            flag=0;
            printf("\nenter block to be allocated for file %d: ",f+1);
            scanf("%d",&bno);
            for(int l=0;l<ind;l++){
                if(check[l]==bno){
                    flag=1;
                    printf("\ncannot allocate!");
                    break;
                }
            }
            if(flag==0){
                alloc(bno, &files[f]);
                check[ind]=bno;
                ind++;
            }
        }
        printf("\nfile %d has been allocated to blocks: ",f+1);
        curr=files[f];
        while(curr!=NULL){
            printf("%d->",curr->bno); 
            curr=curr->next;
        }    
    }
}
