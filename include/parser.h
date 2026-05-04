#ifndef PARSER_H
#define PARSER_H

#define MAX_USER 50
#define MAX_IP 50
#define MAX_EVENT 20

typedef struct {
    char timestamp[30];
    char user[MAX_USER];
    char ip[MAX_IP];
    char event[MAX_EVENT]; // "SUCCESS" or "FAIL"
} LogEntry;

int parse_log_line(char *line, LogEntry *entry);

#endif