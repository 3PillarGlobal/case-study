#include "logger.h"
#include <iostream>
#include <fstream>

void Logger::log(const std::string& message) const
{
  logs_.push_back(message);
}

void Logger::flushToFile(const std::string& fileName) const
{
  std::ofstream file(fileName);
  for (auto str : logs_) 
  {
    file << str << std::endl;
  }

  file.close();
  logs_.clear();
}