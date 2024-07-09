#include<stdio.h>
#include<stdlib.h>

void fcfs(int arr[], int size, int head){
    int seektime;
    seektime=abs(head-arr[0]);
    for(int i=0;i<size-1;i++){
        seektime+=abs(arr[i]-arr[i+1]);
    }
    printf("\nseektime =%d",seektime);
}

void main(){
    int size, req[10], head;
    printf("\nenter num of requests:");
    scanf("%d",&size);
    printf("\nenter request sequence:");
    for(int i=0;i<size;i++){
        scanf("%d",&req[i]);
    }
    printf("\nenter initial head position:");
    scanf("%d",&head);
    fcfs(req, size, head);
}
