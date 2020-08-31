#pragma once

#include "logger.h"
#include <memory>

class Loggable
{
public:
  Loggable() = default;
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
