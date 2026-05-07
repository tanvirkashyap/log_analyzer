#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse_log_line(char *line, LogEntry *entry) {
    // Expected format: 2026-05-05 admin 192.168.1.1 FAIL
    return sscanf(line, "%29s %49s %49s %19s",
                  entry->timestamp,
                  entry->user,
                  entry->ip,
                  entry->event) == 4;
}