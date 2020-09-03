#pragma once

#include <string>
#include <list>
#include <sstream>
#include <algorithm>

class Logger {
public:
  Logger() = default;
  Logger(const Logger& other) = delete;
  void operator=(const Logger& other) = delete;

  template<typename... Type>
  void log(Type&&... args) const;

protected:
  virtual void write() const = 0;
  virtual void flush() const = 0;
  mutable std::list<std::string> logs_;
};

template<typename... Type>
void Logger::log(Type&&... args) const
{
  std::ostringstream messageStream;
  const auto dummy = {(messageStream << args << " ", 0)...};
  (void)dummy;

  logs_.emplace_back(messageStream.str());
  write();
}

class ConsoleLogger: public Logger {
  void write() const override;
  void flush() const override;

public:
  ~ConsoleLogger();
};