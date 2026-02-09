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
    MYSYSLOG_CRITICAL
} mysyslog_level_t;

typedef struct {
    long timestamp;
    const char* log_level;
    const char* process;
    const char* message;
} mysyslog_record_t;

/*
 * Основная API функция библиотеки
 */
int mysyslog(const char* msg, int level, int driver, int format, const char* path);

/*
 * Вспомогательная функция: уровень -> строка
 */
const char* mysyslog_level_to_string(int level);

#ifdef __cplusplus
}
#endif

#endif // MYSYSLOG_H