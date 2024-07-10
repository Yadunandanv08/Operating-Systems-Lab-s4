#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
int buffer[10];
sem_t mutex;
sem_t full;
sem_t empty;
int in=0,out=0;
void *producer(void *args){
    for(int i=0;i<10;i++){
        sleep(1);
        int item;
        sem_wait(&empty);
        sem_wait(&mutex);
        item=rand()%100;
        buffer[in]=item;
        in=(in+1)%10;
        printf("produced %d\n",item);
        sem_post(&mutex);
        sem_post(&full);
    }
    
}

void *consumer(void *args){
    for(int i=0;i<10;i++){
        sleep(2);
        int item;
        sem_wait(&full);
        sem_wait(&mutex);
        item=rand()%100;
        item=buffer[out];
        out=(out+1)%10;
        printf("consumed %d\n",item);
        sem_post(&mutex);
        sem_post(&empty);
    }
    
}

void main(){
    sem_init(&mutex,0,1);
    sem_init(&empty,0,10);
    sem_init(&full,0,0);
    
    pthread_t p,c;
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    
    
}

