#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
    int pid;
    pid_t=fork();
    if(pid<0){
         printf("failed!");
         exit(1);
    }
    else if(pid==0){
        printf("child pid=%d\n",getpid());
    }
    else{
         printf("parent pid=%d\n",getppid());
    }
}
