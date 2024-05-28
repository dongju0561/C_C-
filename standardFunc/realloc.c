#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
    int *num = (int *)malloc(sizeof(int));

    printf("%p\n",num);

    num = realloc(num, sizeof(2*sizeof(int)));

    printf("%p\n", num);

}