/*
test.txt 파일을 불러와 중복되는 단어들이 몇개가 있는지 세어주는 프로그램 
*/
#include <stdio.h>
#include <string.h>
#include "map.h"

int main(){
    //텍스트 파일 읽어오기
    FILE *fp;
    int c;
    char str[1000] = ""; // 문자열 초기화
    int index = 0; // str에 문자를 추가할 위치를 추적
    HashTable *hashTable = create_table();

    //읽기 시작
    fp = fopen("test.txt", "r");

    if(fp == NULL){
        printf("해당 파일은 존재하지 않습니다.\n");
    }
    else
    {
        printf("파일열기 성공\n");
    }

    while((c = fgetc(fp)) != EOF) {
        str[index++] = c;
    }
    str[index] = '\0'; // 문자열 종료
    
    //읽기 끝

    fclose(fp);

    //단어 찾기
    char *token = strtok(str, " ");
    while (token != NULL) {
        if(get(hashTable,token) == -1){
            insert(hashTable,token,1);
        }
        else{
            insert(hashTable,token,get(hashTable,token)+1);
        }
        token = strtok(NULL, " "); // 다음 토큰을 가져옵니다.
    }

    //단어 갯수 세기
    //해쉬테이블의 entry 배열을 순회하면서 해당공간의 일련의 entry를 출력하는 함수
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = hashTable->entries[i];
        while (entry != NULL) {
            printf("%s : %d\n", entry->key, entry->value);
            entry = entry->next;
        }
    }
}
