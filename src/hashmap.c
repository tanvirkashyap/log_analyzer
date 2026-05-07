#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

unsigned int hash(char *key) {
    unsigned int h = 0;
    while (*key)
        h = (h * 31) + *key++;
    return h % TABLE_SIZE;
}

void init_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++)
        table->buckets[i] = NULL;
}

Node* find(HashTable *table, char *ip) {
    unsigned int index = hash(ip);
    Node *curr = table->buckets[index];

    while (curr) {
        if (strcmp(curr->ip, ip) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}



void insert_fail(HashTable *table, char *ip) {
    unsigned int index = hash(ip);
    Node *node = find(table, ip);

    if (node) {
        node->fail_count++;
        return;
    }

    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return; // Safety check for malloc failure

    strncpy(new_node->ip, ip, 49);
    new_node->ip[49] = '\0';
    new_node->fail_count = 1;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

// NEW: Cleanup function to prevent memory leaks
void free_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = table->buckets[i];
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        table->buckets[i] = NULL;
    }
}

