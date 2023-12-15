#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
#include<semaphore.h>

int buffer[5];
int count = 0;
// semaphore variable
sem_t empty, full;

//mutex variable
// mutex is locking and unlocking mechanism
pthread_mutex_t mutex;

void *producer(void * arg) {
    long int num = (long int)arg;
    
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
        // creating data
        buffer[count] = rand()%10;
        printf("\nProducer%ld is Produced %d", num+1, buffer[count]);
        count++;
        sleep(1);
    pthread_mutex_unlock(&mutex);
    // incermenting the full value
    sem_wait(&full);
}

void *consumer(void * arg) {
    long int num = (long int)arg;

    
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
        count--; 
        printf("\nconsumer%ld has consumed %d\n",num+1, buffer[count]);
        sleep(1);
    pthread_mutex_unlock(&mutex);
    sem_wait(&empty);
}

int main() {

    // number of producer and number of consumer 
    int np, nc;

    // thread variable 
    pthread_t p[10], c[10];

    printf("enter number of producer and consumer ");
    np = nc = 5;

    // initialization of semaphore variable
    // variable name, shared or not, inital value
    sem_init(&empty, 0, 5);
    sem_init(&full,0,0);

    // initalizaton of mutex
    pthread_mutex_init(&mutex, NULL);

    // create producer thread
    for(unsigned long int i=0;i<np;i++)
        pthread_create(&p[i], NULL, producer, (void *)i);

    // create producer thread
    for(unsigned long int i=0;i<nc;i++) 
        pthread_create(&c[i],NULL, consumer, (void *)i);


    return 0;
}