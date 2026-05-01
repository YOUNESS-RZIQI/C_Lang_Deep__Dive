#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex_lock;
pthread_cond_t cond_lock;

struct st 
{
    int id;
};

void *print(void *arg)
{
    struct st* id = (struct st*)arg;

    // pthread_mutex_lock(&mutex_lock);

    // pthread_cond_wait(&cond_lock, &mutex_lock);
    // printf("i am cond of thread %d\n", id->id);


    // pthread_cond_wait(&cond_lock, &mutex_lock);
    // printf("i am cond of thread %d\n", id->id);


    // pthread_cond_wait(&cond_lock, &mutex_lock);
    // printf("\n\ni am cond of thread %d\n", id->id);

    
    // int result = pthread_mutex_unlock(&mutex_lock);
    //  result = pthread_mutex_unlock(&mutex_lock);
    
    // printf("\nresult = %d\n", result);


    return NULL;
}


int main()
{
    pthread_t th[2];
    struct st* id[2];


    pthread_cond_init(&cond_lock, NULL);

    id[0] = malloc(sizeof(struct st));
    id[1] = malloc(sizeof(struct st));

    id[0]->id = 1;
    id[1]->id = 2;
    pthread_create(&th[0], NULL, print, (void*)id[0]);
    pthread_create(&th[1], NULL, print, (void*)id[1]);



    pthread_join(th[0], NULL);
    pthread_join(th[1], NULL);
    
    return 0;
}




//     !   !    here    ->  ->   4) pthread_mutex_destroy   GPT

this is my message to hem :

now about the mutex i have some quetions about it : 
1) when the pthread_mutex_init fails , and what is the return value of it in fail and in success
2) when the pthread_mutex_lock fails , and what is the return value of it in fail and in success, and what if we did lock to the same thread twice ? what is going to happen ?
3) when the pthread_mutex_unlock fails , and what is the return value of it in fail and in success, and what if we unlock twice , and what if we unlock without do the lock first ?
4) when the pthread_mutex_destroy fails , and what is the return value of it in fail and in success, and what if we destroy twice the same thread , and what if we did destroy without do the init first ?

the same for cond:
1) when the pthread_cond_init fails , and what is the return value of it in fail and in success
2) when the pthread_cond_ fails , and what is the return value of it in fail and in success, and what if we did lock to the same thread twice ? what is going to happen ?
3) when the pthread_mutex_unlock fails , and what is the return value of it in fail and in success, and what if we unlock twice , and what if we unlock without do the lock first ?