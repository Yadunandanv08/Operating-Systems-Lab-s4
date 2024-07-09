#include<stdio.h>

void firstFit(int process[], int blocks[], int pnum, int bnum){
    int flag;
    for(int i=0;i<pnum;i++){
        flag=0;
        for(int j=0;j<bnum;j++){
            if(process[i]<=blocks[j]){
                blocks[j]-=process[i];
                printf("process %d allocated to block %d!\n",i+1,j+1);
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("process %d cannot be allocated!\n",i+1);
        }
    }
}

void main(){
    int pno,bno,process[10],blocks[10];
    printf("enter number of processes:");
    scanf("%d",&pno);
    printf("\nenter size of each process:\n");
    for(int i=0;i<pno;i++){
        printf("process %d:",i+1);
        scanf("%d",&process[i]);
    }
    printf("enter number of blocks:");
    scanf("%d",&bno);
    printf("\nenter size of each blocks:\n");
    for(int i=0;i<bno;i++){
        printf("block %d:",i+1);
        scanf("%d",&blocks[i]);
    }
    firstFit(process,blocks,pno,bno);
}
