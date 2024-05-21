#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

void *counter1(){
    for (int i = 0; i < 10; i++)
    {
        time_t current_time;
        struct tm *local_time;

        // 현재 시간 가져오기
        time(&current_time);

        // 현재 시간을 로컬 시간으로 변환
        local_time = localtime(&current_time);

        printf("counter1 : %d | 현재 시간: %d-%02d-%02d %02d:%02d:%02d\n",
            i,
            local_time->tm_year + 1900, // tm_year는 1900년을 기준으로 하기 때문에 1900을 더합니다.
            local_time->tm_mon + 1,     // tm_mon은 0부터 시작하기 때문에 1을 더합니다.
            local_time->tm_mday,
            local_time->tm_hour,
            local_time->tm_min,
            local_time->tm_sec
        );
        // fflush(stdout);
        sleep(1);
    }
}

void *counter2(){
    for (int i = 0; i < 10; i++)
    {
        time_t current_time;
        struct tm *local_time;

        // 현재 시간 가져오기
        time(&current_time);

        // 현재 시간을 로컬 시간으로 변환
        local_time = localtime(&current_time);

        printf("counter2 : %d | 현재 시간: %d-%02d-%02d %02d:%02d:%02d\n",
            i,
            local_time->tm_year + 1900, // tm_year는 1900년을 기준으로 하기 때문에 1900을 더합니다.
            local_time->tm_mon + 1,     // tm_mon은 0부터 시작하기 때문에 1을 더합니다.
            local_time->tm_mday,
            local_time->tm_hour,
            local_time->tm_min,
            local_time->tm_sec
        );
        // fflush(stdout);
        sleep(1);
    }
}

int main(){
    pthread_t cnter1, cnter2;
    pthread_create(&cnter1, NULL, counter1,NULL);
    pthread_create(&cnter2, NULL, counter2,NULL);

    pthread_join(cnter1,NULL);
    pthread_join(cnter2,NULL);
}