#include<stdio.h>
#include<stdlib.h>

int blocks[10];

void alloc(int start, int length, int i){
    int flag=0, count=0;
    if((start+length)>10){
        printf("cannot allocate!\n");
    }
    else{
        for(int i=start;i<(start+length);i++){
            if(blocks[i]==0){
                blocks[i]=1;
                count++;
            }
            else{
                printf("cannot allocate!\n");
                flag=1;
                for(int k=start;k<count;k++){
                    blocks[i]=0;
                }
                break;
            }
        }
        if(flag==0){
             printf("file %d allocated from %d to %d\n", i, start, (start+length-1));
        }
    }
}

void main(){
    int num, start, length;
    printf("enter num of files:");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("enter start of file %d:",i);
        scanf("%d",&start);
        printf("enter length of file %d:",i);
        scanf("%d",&length);
        alloc(start, length, i);
    }
}
