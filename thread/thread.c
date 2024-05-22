/*
pthread_create()
스레드를 생성하는 함수입니다.

pthread_exit()
스레드를 종료하는 함수입니다. 종료 이후에 인자값을 pthread_join의 두번째 인자로 전달이 됩니다.

pthread_join()
스레드의 종료 시점을 기다리는 함수입니다. pthread_exit으로부터 

*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_func(void *arg) {
    // 쓰레드 작업 수행
    sleep(2);

    // 쓰레드 종료 시 반환할 값 설정
    pthread_exit((void *)42);
}

int main() {
    pthread_t thread;
    void *exit_status;

    // 쓰레드 생성
    pthread_create(&thread, NULL, thread_func, NULL);

    // 쓰레드 종료 대기 및 반환값 저장
    pthread_join(thread, &exit_status);

    // 쓰레드 종료 상태 출력
    printf("Thread exit status: %ld\n", (long)exit_status);

    return 0;
}
