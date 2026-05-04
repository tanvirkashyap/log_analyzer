#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "hashmap.h"

#define THRESHOLD 5

void analyze_logs(FILE *fp) {
    char line[256];
    LogEntry entry;
    HashTable table;

    init_table(&table);

    while (fgets(line, sizeof(line), fp)) {
        if (!parse_log_line(line, &entry))
            continue;

        if (strcmp(entry.event, "FAIL") == 0) {
            insert_fail(&table, entry.ip);

            Node *node = find(&table, entry.ip);
            if (node->fail_count == THRESHOLD) {
                printf("[ALERT] Brute-force suspected from IP: %s\n", entry.ip);
            }
        }
    }
}