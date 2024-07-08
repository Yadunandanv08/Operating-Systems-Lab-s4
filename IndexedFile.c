#include<stdio.h>
#include<stdlib.h>

struct indexBlock{
    int dataBlock[10];
};

void initialize(struct indexBlock* n){
    for(int i=0;i<10;i++){
        n->dataBlock[i]=-1;
    }
}

void alloc(struct indexBlock* n, int blockNo){
    for(int i=0;i<10;i++){
        if(n->dataBlock[i]==-1){
            n->dataBlock[i]=blockNo;
            break;
        }   
    }
}

void read(struct indexBlock* n, int blockNo){
    int flag=0;
    for(int i=0;i<10;i++){
        if(n->dataBlock[i]==blockNo){
            printf("read from block %d\n", blockNo);
            flag=1;
        }
    }
    if(flag==0){
        printf("block %d is not allocated!", blockNo);
    }
}

void main(){
    struct indexBlock* indexBlock;
    int blockNum, b;
    initialize(indexBlock);
    printf("\nenter number of blocks:");
    scanf("%d",&blockNum);
    printf("enter datablocks to be allocated:");
    for(int i=0;i<blockNum;i++){
        scanf("%d",&b);
        alloc(indexBlock, b);
    }
    printf("enter datablocks to be read from:");
    for(int i=0;i<blockNum;i++){
        scanf("%d",&b);
        read(indexBlock, b);
    }
}
