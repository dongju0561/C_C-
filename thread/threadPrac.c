#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int buffer = 0;

void *generate(){
    //난수 생성
    int random_number = rand();

    pthread_mutex_lock(&mutex);
    buffer = random_number;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    
    pthread_exit(NULL);
}

void *consume(){
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("생성된 값: %d\n",buffer);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(){
    // 시드를 설정합니다.
    srand(time(NULL));

    pthread_t generator, consumer;

    //*주의 : wait명령어 이후 signal명령어를 보내야 한다.
    pthread_create(&consumer,NULL,consume,NULL);
    pthread_create(&generator,NULL,generate,NULL);
    
    pthread_join(generator,NULL);
    pthread_join(consumer,NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    return 0;
}