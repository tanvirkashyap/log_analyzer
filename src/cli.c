#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "analyzer.h"

void handle_cli(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./log_analyzer <logfile>\n");
        return;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    if (argc == 2) {
        analyze_logs(fp);
    } else if (strcmp(argv[2], "--detect") == 0) {
        analyze_logs(fp); // later you can customize
    } else if (strcmp(argv[2], "--stats") == 0) {
        printf("Stats feature coming soon\n");
    }

    fclose(fp);
}