#include <stdio.h>

void analyze_logs(FILE *fp);

int main() {
    FILE *fp = fopen("data/sample.log", "r");

    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    analyze_logs(fp);

    fclose(fp);
    return 0;
}