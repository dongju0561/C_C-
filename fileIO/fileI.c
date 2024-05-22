#include<stdio.h>

int main(){
    FILE *fp;
    int c;

    fp = fopen("test.txt", "r");

    if(fp == NULL){
        printf("해당 파일은 존재하지 않습니다.\n");
    }
    else
    {
        printf("파일열기 성공\n");
    }

    while((c = fgetc(fp)) != EOF){
        putchar(c);
    }

    fclose(fp);

    return 0;
}