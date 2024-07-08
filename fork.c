#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
         printf("failed!");
         exit(1);
    }
    else if(pid==0){
        printf("child pid=%d\n",getpid());
    }
    else{
         printf("parent pid=%d\n",getpid());
    }
}
