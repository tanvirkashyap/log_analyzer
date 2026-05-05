#include <stdio.h>
#include "analyzer.h" // Added missing header[cite: 1]

int main() {
    FILE *fp = fopen("data/sample.log", "r");
    if (!fp) {
        perror("Error opening file"); // More descriptive error[cite: 10]
        return 1;
    }
    analyze_logs(fp);
    fclose(fp);
    return 0;
}