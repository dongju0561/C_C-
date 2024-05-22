#include<stdio.h>

struct Struct1
{
    int age;
    char name[10];
};


typedef struct Struct2
{
    char name[9];
    int age;
}struct2;

int main(){
    struct Struct1 s1;

    //타입이 같은 구조체 선언 방식이 다를뿐
    struct Struct2 s2 = {1,"hello"};
    struct2 s2_1;

    printf("%d",s2.age);
}