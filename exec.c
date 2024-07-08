#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("failed!");
        exit(1);
    }
    else if(pid==0){
        execlp("/bin/date","date",NULL);
        exit(0);
    }
    else{
        printf("parent pid=%d\n",getpid());
        wait(NULL);
        exit(0);
    }
}
