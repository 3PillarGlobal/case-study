#include "logger.h"
#include <iostream>

void Logger::log(const std::string& message)
{
  logs_.push_back(message);
};
