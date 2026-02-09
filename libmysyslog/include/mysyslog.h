#ifndef MYSYSLOG_H
#define MYSYSLOG_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MYSYSLOG_DEBUG = 0,
    MYSYSLOG_INFO,
    MYSYSLOG_WARN,
    MYSYSLOG_ERROR,
    MYSYSLOG_CRITICAL,
    MYSYSLOG_DRIVER_TEXT = 0,
    MYSYSLOG_DRIVER_JSON = 1
} mysyslog_level_t;

typedef struct {
    long timestamp;
    const char* log_level;
    const char* process;
    const char* message;
} mysyslog_record_t;


int mysyslog(const char* msg, int level, int driver, int format, const char* path);


const char* mysyslog_level_to_string(int level);


#ifdef __cplusplus
}
#endif

#endif 