#include <stdio.h>

int main() {
    int age;
    char name[100];
    char number[100];
    FILE *file = fopen("hello.txt", "r");
    

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fscanf(file, "%d %s %s", &age, name, number) == 3)
    {
        printf("age : %d, name : %s, number : %s\n",age, name, number);
    }
    

    fclose(file);
    return 0;
}