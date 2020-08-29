#pragma once

#include "logger.h"

class Loggable
{
public:
  Loggable() = default;
  Loggable(Logger* logger) : logger_(logger) {}

  const Logger& logger() const { return *logger_; }
private:
  std::unique_ptr<Logger> logger_;
};

#define LOG_TO(logger, msg)               \
  do {                                    \
    try {                                 \
        (logger).log((msg));              \
    } catch (...) {                       \
    }                                     \
  } while (0)

#define LOG(msg) LOG_TO((logger()), msg)

#define DUMP(logger)  \
  try {               \
    (logger).dump();  \
  } catch( ...) {     \
  }                   

#define DUMP_LOGS() DUMP(logger())
