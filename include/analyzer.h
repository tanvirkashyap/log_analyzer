#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>

// Core analysis function
void analyze_logs(FILE *fp);

// Optional: advanced detection APIs
void detect_bruteforce();
void detect_suspicious_users();
void detect_traffic_spike();

#endif