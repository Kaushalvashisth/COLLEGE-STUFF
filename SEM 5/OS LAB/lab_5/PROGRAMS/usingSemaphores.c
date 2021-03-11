#include <stdio.h> 
#include <stdlib.h>
#include <semaphore.h> 
#include <time.h> 
#include <pthread.h>

#define N 10
sem_t  bin_sem,  full,  empty; int front = 0;
int rear = 0; int CQueue[N];

int produce_item()
{
    int p = 1 + rand() % 300; return p;
}

void  insert_item(int  item)
{
    if (rear == N) rear = 0;
    CQueue[rear++]  =  item;
    printf("The  Inserted  Item  is  %d\n",  item);
}

int remove_item()
{
    if (front == N) front = 0;
    int e = CQueue[front++]; return e;
}

void  consume_item(int  item)
{
    printf("The  Consumed  Item  is  %d\n",  item);
}

void *producer(void *a)
{
int item, i;
    for (i = 0; i < N; i++)
    {
        item = produce_item();
        sem_wait(&empty);
        sem_wait(&bin_sem);
        insert_item(item);
        sem_post(&bin_sem);
        sem_post(&full);
    }
}

void *consumer(void *a)
{
int item, i;
    for (i = 0; i < N; i++)
    {
    sem_wait(&full);
    sem_wait(&bin_sem);
    //  removing  item:  critical  region 
    item = remove_item(); 
    consume_item(item);
    sem_post(&bin_sem);
    sem_post(&empty);
    }
}

int main(int argc, char **argv)
{
    //  initializing  semaphores
    sem_init(&bin_sem, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, N);

    //initializing pthread_t th1, th2; int a;
    pthread_t th1, th2; int a;
    // creating threads
    pthread_create(&th1, NULL, producer, NULL); 
    pthread_create(&th2, NULL, consumer, NULL); 
    pthread_join(th1, NULL);
    pthread_join(th2, NULL); return (EXIT_SUCCESS);
}
