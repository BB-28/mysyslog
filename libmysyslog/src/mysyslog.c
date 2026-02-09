#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/mysyslog.h"

const char* mysyslog_level_to_string(int level)
{
    switch (level) {
        case MYSYSLOG_DEBUG: return "DEBUG";
        case MYSYSLOG_INFO: return "INFO";
        case MYSYSLOG_WARN: return "WARN";
        case MYSYSLOG_ERROR: return "ERROR";
        case MYSYSLOG_CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

int mysyslog(const char* msg, int level, int driver, int format, const char* path)
{
    (void)driver; 
    (void)format; 

    if (msg == NULL || path == NULL) {
        return -1;
    }

    long ts = (long)time(NULL);
    const char* lvl = mysyslog_level_to_string(level);


    const char* process = "example-app";

    FILE* f = fopen(path, "a");
    if (!f) {
        return -1;
    }

   
    fprintf(f, "%ld %s %s %s\n", ts, lvl, process, msg);
    fclose(f);

    return 0;
}