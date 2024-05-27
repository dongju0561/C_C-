#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *str = "hello world";//정적 할당
    char *newStr;

    newStr = strdup(str);//동적 할당

    printf("str = %s\n",str);
    printf("newStr = %s\n",str);

    free(newStr);
}