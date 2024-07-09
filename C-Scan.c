#include<stdio.h>
#include<stdlib.h>

void scan(int arr[], int size, int head){
    int seektime, temp, tot=200, ind;
    
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(arr[i]>head){
            ind=i;
            break;
        }
    }
    seektime=abs(head-arr[ind]);
    for(int i=ind;i<size-1;i++){
        seektime+=abs(arr[i+1]-arr[i]);
    }
    seektime+=abs(tot-1-arr[size-1]);
    seektime+=tot-1;
    seektime+=arr[0];
    for(int i=0;i<ind-1;i++){
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
    scan(req, size, head);
}
