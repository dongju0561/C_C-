#include <stdio.h>

int main() {
    char string[20];
    char c;

    printf("문자열을 입력하세요: ");
    scanf("%s", string);

    // getchar로 개행 문자를 읽어옵니다.
    getchar();

    printf("두 번째 문자를 입력하세요: ");
    scanf("%c", &c);

    printf("입력한 문자열: %s\n", string);
    printf("두 번째 입력한 문자: %c\n", c);

    return 0;
}