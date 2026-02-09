#include <stdio.h>

#include "mysyslog.h"
#include "mysyslog_driver.h"

static void json_escape(const char* src, char* dst, size_t dst_size)
{
    size_t j = 0;
    for (size_t i = 0; src[i] != '\0' && j + 2 < dst_size; i++) {
        if (src[i] == '"' || src[i] == '\\') {
            dst[j++] = '\\';
        }
        dst[j++] = src[i];
    }
    dst[j] = '\0';
}

int mysyslog_driver_write(const mysyslog_record_t* rec, const char* path)
{
    if (!rec || !path) return -1;

    FILE* f = fopen(path, "a");
    if (!f) return -1;

    char msg_escaped[4096];
    json_escape(rec->message, msg_escaped, sizeof(msg_escaped));

    fprintf(f,
        "{\"timestamp\":%ld,\"log_level\":\"%s\",\"process\":\"%s\",\"message\":\"%s\"}\n",
        rec->timestamp,
        rec->log_level,
        rec->process,
        msg_escaped
    );

    fclose(f);
    return 0;
}