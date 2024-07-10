#include<stdio.h>

struct frame{
    int page;
    int rec;
    int fifo;
}frames[3];

int pages[100], pageFaults=0;

void print(struct frame frames[]){
    for(int i=0;i<3;i++){
        printf("%d\t",frames[i].page);
    }
    printf("\n");
}

void lru(int n){
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<3;j++){
            if(frames[j].page==pages[i]){
                printf("%d already exists!\n",pages[i]);
                found=1;
                for(int p=0;p<3;p++){
                    frames[p].fifo++;
                    frames[p].rec++;
                }
                frames[j].rec=1;
                print(frames);
                break;
            }
        }
        if(found==0){
            for(int j=0;j<3;j++){
                int max=0;
                for(int k=0;k<3;k++){
                    if(frames[k].page==-1){
                        max=k;
                        break;
                    }
                    else if(frames[k].rec>frames[max].rec ||frames[k].rec==frames[max].rec && frames[k].fifo>frames[max].fifo){
                        max=k;
                    }
                }
                for(int p=0;p<3;p++){
                    frames[p].fifo++;
                    frames[p].rec++;
                }
                frames[max].page=pages[i];
                frames[max].rec=1;
                frames[max].fifo=1;
                print(frames);
                pageFaults++;
                break;  
            }
        }
    }
}

void main(){
    int pg;
    printf("\nenter number of pages: ");
    scanf("%d",&pg);
    printf("\nenter page sequence: ");
    for(int i=0;i<pg;i++){
        scanf("%d",&pages[i]);
    }
    for(int i=0;i<3;i++){
        frames[i].page=-1;
        frames[i].rec=0;
        frames[i].fifo=0;
    }
    lru(pg);
    printf("Page Faults=%d", pageFaults);
}
