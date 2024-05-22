#include <pthread.h>
/*
pthread_cond_wait(cond, mutex);
해당 함수가 실행된 스레드의 동작을 일시정지 시키는 함수입니다.

pthread_cond_signal(cond);
pthread_cond_wait를 통해 일시정지된 스레드중에 하나를 재실행 시키는 함수입니다.

pthread_cond_broadcast(cond);
pthread_cond_wait를 통해 일시정지된 스레드들을 모두 재실행 시키는 함수입니다.

*/
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *counter1(void *arg) {
    for (int i = 0; i < 10; i++) {   
        if (i == 2) {
            pthread_mutex_lock(&mutex1);
            pthread_cond_broadcast(&cond1);
            pthread_mutex_unlock(&mutex1);
        }
        printf("thread1 : %d\n", i);
        sleep(1);
    }
    return NULL;
}

void *counter2(void *arg) {
    pthread_mutex_lock(&mutex1);
    pthread_cond_wait(&cond1, &mutex1);
    pthread_mutex_unlock(&mutex1);
    
    for (int i = 0; i < 10; i++) {   
        printf("thread2 : %d\n", i);
        sleep(1);
    }
    return NULL;
}

void *counter3(void *arg) {
    pthread_mutex_lock(&mutex1);
    pthread_cond_wait(&cond1, &mutex1);
    pthread_mutex_unlock(&mutex1);
    
    for (int i = 0; i < 10; i++) {   
        printf("thread3 : %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t c1, c2, c3;

    pthread_create(&c1, NULL, counter1, NULL);
    pthread_create(&c2, NULL, counter2, NULL);
    pthread_create(&c3, NULL, counter3, NULL);

    pthread_join(c1, NULL);
    pthread_join(c2, NULL);
    pthread_join(c3, NULL);

    return 0;
}
