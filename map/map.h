#ifndef MAP_H
#define MAP_H

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

HashTable *create_table();
void insert(HashTable *table, const char *key, int value);
int get(HashTable *table, const char *key);
void free_table(HashTable *table);

#endif