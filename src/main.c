#include <stdio.h>
#include "analyzer.h"
#include "cli.h"

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        handle_cli(argc, argv);
    } else {
        FILE *fp = fopen("data/sample.log", "r");
        if (!fp) {
            perror("Error opening file");
            return 1;
        }
        analyze_logs(fp);
        fclose(fp);
    }
    return 0;
}