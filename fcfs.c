#include<stdio.h>

struct process{
    int pno;
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
}p[10];

void fcfs(struct process p[], int pno){
    struct process temp;
    float total_tat=0,total_wt=0;
    for(int i=0;i<pno-1;i++){
        for(int j=0;j<pno-i-1;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    p[0].wt=0;
    p[0].ct=p[0].bt+p[0].at;
    p[0].tat=p[0].ct-p[0].at;
    total_tat+=p[0].tat;
    total_wt+=p[0].wt;
    
    for(int i=1;i<pno;i++){
        p[i].ct=p[i-1].ct+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        total_tat+=p[i].tat;
        total_wt+=p[i].wt;
    }
    
    printf("\n\tpno\tat\tbt\ttat\twt\n");
    for(int i=0;i<pno;i++){
        printf("\n\t%d\t%d\t%d\t%d\t%d\n",p[i].pno+1,p[i].at,p[i].bt,p[i].tat,p[i].wt);
    }
    printf("average turaround time=%f\n",total_tat/pno);
    printf("average waiting time=%f",total_wt/pno);
}

void main(){
    int pno;
    printf("enter the number of processes:");
    scanf("%d",&pno);
    printf("\nenter arrival times:\n");
    for(int i=0;i<pno;i++){
        printf("process %d:",i+1);
        scanf("%d",&p[i].at);
        p[i].pno=i;
    }
    
    printf("\nenter burst times:\n");
    for(int i=0;i<pno;i++){
        printf("process %d:",i+1);
        scanf("%d",&p[i].bt);
    }
    
    fcfs(p,pno);
   
}
