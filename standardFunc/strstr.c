#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "This is a simple string";
    char* pch;
    if((pch = strstr(str, "simplf")) != NULL)
    {
        strncpy(pch, "sample", 6);
        puts(str);    
    }
    else
    {
        printf("일치하는 단어가 없습니다.");
    }
    return 0;
}