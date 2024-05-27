#include <stdio.h>
int main() {
    char str[80];
    float f, f1;
    FILE* pFile;

    pFile = fopen("myfile.txt", "w+");
    fprintf(pFile, "%f %s", 3.1416, "PI");
    rewind(pFile);
    fscanf(pFile, "%f", &f);
    fscanf(pFile, "%s", str);
    fscanf(pFile, "%f", &f1);
    fclose(pFile);
    printf("I have read: %f, %s \n", f, str);
    return 0;
}