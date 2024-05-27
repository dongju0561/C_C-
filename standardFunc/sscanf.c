#include <stdio.h>
int main() {
    char str[30] = "1234 abcd";
    int i;
    char ch[4];

    sscanf(str, "%d %s", &i, ch);

    printf("Number from : '%s' \n", str);
    printf("number i : %d \n", i);
    printf("number j : %s \n", ch);

    return 0;
}