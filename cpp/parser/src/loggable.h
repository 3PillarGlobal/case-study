#pragma once

#include "logger.h"
#include <memory>

class Loggable
{
public:
  Loggable(): logger_(new Logger) {}

  inline void log(const std::string& message) const {
      logger_->log(message);
  }

private:
  std::unique_ptr<Logger> logger_;
};