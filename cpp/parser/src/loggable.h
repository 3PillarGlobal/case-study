#pragma once

#include "logger.h"

class Loggable
{
public:
// the default constructor will leave the logger_ uninitialized, which is used in LOG,
// so we need to initialize it here with a default logger
  Loggable() : logger_(new Logger){}
  Loggable(Logger* logger): logger_(logger) {}

  const Logger& logger() const { return *logger_; }
private:
  std::unique_ptr<Logger> logger_;
};

#define LOG_TO(logger, msg)               \
  do {                                    \
    try {                                 \
        (logger).log((msg));              \
    } catch (const std::exception& e) {   \
    }                                     \
  } while (0)

#define LOG(msg) LOG_TO((logger()), msg)

// Improvement, log as a stream
#define LOG_STREAM(...)                   \
  do {                                    \
    std::ostringstream str;               \
    str << __VA_ARGS__;                   \
    LOG(str.str());                       \
  } while (0)
