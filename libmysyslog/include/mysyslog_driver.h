#ifndef MYSYSLOG_DRIVER_H
#define MYSYSLOG_DRIVER_H

#include "mysyslog.h"

typedef int (*mysyslog_driver_write_t)(const mysyslog_record_t* rec, const char* path);

#define MYSYSLOG_DRIVER_SYMBOL "mysyslog_driver_write"

#endif