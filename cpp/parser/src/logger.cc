#include "logger.h"

void Logger::log(const std::string& message) const
{
  logs_.push_back(message);
};
