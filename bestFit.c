#include<stdio.h>

void bestFit(int process[], int blocks[], int pnum, int bnum){
    int flag,min;
    for(int i=0;i<pnum;i++){
        flag=0;
        min=-1;
        for(int j=0;j<bnum;j++){
            if(blocks[j]>=process[i]){
                if(min==-1 || blocks[min]>=blocks[j]){
                    min=j;
                }
            }
        }
       
        if(process[i]<=blocks[min]){
            blocks[min]-=process[i];
            flag=1;
            printf("\nprocess %d allocated to block %d",i+1,min+1);
        }
    
        if(flag==0){
            printf("\nprocess %d cannot be allocated",i+1);
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
    bestFit(process,blocks,pno,bno);
}
