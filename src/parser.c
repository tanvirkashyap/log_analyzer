#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse_log_line(char *line, LogEntry *entry) {
    // Example format:
    // "2026-04-25 10:15:32 user=admin ip=192.168.1.8 event=FAIL"

    char *token = strtok(line, " ");
    if (!token) return 0;
    strcpy(entry->timestamp, token);

    token = strtok(NULL, " ");
    if (!token) return 0;
    strcat(entry->timestamp, " ");
    strcat(entry->timestamp, token);

    while ((token = strtok(NULL, " ")) != NULL) {
        if (strncmp(token, "user=", 5) == 0)
            strcpy(entry->user, token + 5);
        else if (strncmp(token, "ip=", 3) == 0)
            strcpy(entry->ip, token + 3);
        else if (strncmp(token, "event=", 6) == 0)
            strcpy(entry->event, token + 6);
    }

    return 1;
}