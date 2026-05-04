#ifndef HASHMAP_H
#define HASHMAP_H

#include "parser.h"

#define TABLE_SIZE 100

typedef struct Node {
    char ip[50];
    int fail_count;
    struct Node *next;
} Node;

typedef struct {
    Node *buckets[TABLE_SIZE];
} HashTable;

void init_table(HashTable *table);
unsigned int hash(char *key);
void insert_fail(HashTable *table, char *ip);
Node* find(HashTable *table, char *ip);

#endif