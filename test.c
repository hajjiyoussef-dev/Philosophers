#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *routing()
{
    printf("hello youssef is nice day\n");
}


int main(int argc , char **argv)
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, &routing, NULL);
    pthread_create(&t2,NULL, &routing, NULL);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return (0);
    
}