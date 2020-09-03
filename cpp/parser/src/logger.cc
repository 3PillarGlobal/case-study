#include "logger.h"

#include <iostream>

void ConsoleLogger::write() const
{
  while(!logs_.empty()) {
    std::cout << logs_.front() << "\n";
    logs_.pop_front();
  }
  flush();
}

void ConsoleLogger::flush() const
{
  std::cout.flush();
}

ConsoleLogger::~ConsoleLogger()
{
  flush();
}
