#pragma once

#include <string>
#include <vector>

class Logger {
public:
  Logger() { logs_.reserve(10); }

  void log(const std::string& message) const;
  void dump() const;
private:
  Logger(const Logger& other);

  std::string rawString(const std::string& text) const;

  mutable std::vector<std::string> logs_;
};
