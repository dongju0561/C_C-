#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    //Entry의 주소를 저장하기 위한 공간
    Entry *entries[TABLE_SIZE];
} HashTable;

//해쉬함수
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

HashTable *create_table() {
    //table 초기화
    HashTable *table = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
    return table;
}

void insert(HashTable *table, const char *key, int value) {
    //해쉬함수를 통해 인덱스를 slot 변수에 저장
    unsigned int slot = hash(key);

    //인덱스에 맵핑되는 테이블 공간 주소를 entry 포인터에 저장
    Entry *entry = table->entries[slot];

    //중복 방지
    //해당 테이블 공간이 비어있다면
    if (entry == NULL) {

        //Entry를 위한 동적할당을 진행하고 Entry 구조체 속성 초기화
        entry = malloc(sizeof(Entry));
        entry->key = strdup(key);
        entry->value = value;
        entry->next = NULL;

        //생성한 Entry의 주소를 Entry와 맵핌된 인덱스으로 테이블 공간에 접근/저장
        table->entries[slot] = entry;

    //만약 인덱스 
    } else {
        Entry *prev;
        //entry가 NULL이 아닌때까지 반복
        while (entry != NULL) {
            //현재 entry의 key와 새로 입력된 key값을 비교
            if (strcmp(entry->key, key) == 0) {
                //만약 key가 동일하다면, 새로운 value로 갱신
                entry->value = value;
                return;
            }
            //key가 일치하지 않는다면

            //다음 entry가 NULL인것을 대비해 prev변수에 entry 할당
            prev = entry;
            entry = entry->next;
        }

        //NULL을 만났다면

        //새로운 메모리공간을 할당하고
        entry = malloc(sizeof(Entry));

        //전달받은 새로운 데이터로 entry에 초기화
        entry->key = strdup(key);
        entry->value = value;
        entry->next = NULL;

        //이전 entry와 현재 새로 만든 entry를 연결해줌
        prev->next = entry;
    }
}

int get(HashTable *table, const char *key) {
    //찾을 값의 key값으로 해쉬 인덱스 받음
    unsigned int slot = hash(key);
    //인덱스에 해당하는 영역으로 접근하고 첫번째 entry의 주소 혹은 NULL값을 할당
    Entry *entry = table->entries[slot];

    //현재 entry가 NULL이 아닌 경우 반복
    while (entry != NULL) {
        //키값을 비교
        if (strcmp(entry->key, key) == 0) {
            //값으면 key와 맵핑된 value 반환
            return entry->value;
        }
        //같지 않다면 다음 entry로 접근
        entry = entry->next;
    }
    return -1;  // 키가 없는 경우
}

void free_table(HashTable *table) {
    //모든 영역을 순회
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = table->entries[i];
        //연결된 entry들을 순회하면서 할당 해제
        while (entry != NULL) {
            Entry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp);
        }
    }
    //table도 할당 해제
    free(table);
}

int main() {
    HashTable *table = create_table();

    insert(table, "apple", 1);
    insert(table, "banana", 2);
    insert(table, "orange", 3);

    printf("apple: %d\n", get(table, "apple"));
    printf("banana: %d\n", get(table, "banana"));
    printf("orange: %d\n", get(table, "orange"));
    printf("grape: %d\n", get(table, "grape"));  // 없는 키

    free_table(table);

    return 0;
}
