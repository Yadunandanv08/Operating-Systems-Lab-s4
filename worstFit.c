#include<stdio.h>

void worstFit(int process[], int blocks[], int pnum, int bnum){
    int flag,max;
    for(int i=0;i<pnum;i++){
        flag=0,max=0;
        for(int j=0;j<bnum;j++){
            if(blocks[max]<=blocks[j]){
                max=j;
            }
        }
       
        if(process[i]<=blocks[max]){
            blocks[max]-=process[i];
            flag=1;
            printf("\nprocess %d allocated to block %d",i+1,max+1);
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
        printf("process %d:",i+1);
        scanf("%d",&blocks[i]);
    }
    worstFit(process,blocks,pno,bno);
}

