#include<stdio.h>

int main(){
    FILE *fp;

    fp = fopen("test.txt", "w");

    if(fp == NULL){
        printf("해당 파일은 존재하지 않습니다.\n");
    }
    else
    {
        printf("파일열기 성공\n");
    }

    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);
    fputs("\nhello world", fp);

    fclose(fp);

    return 0;
}