#pragma once

#include <string>
#include <vector>

class Logger {
public:
  Logger(){ logs_.reserve(10); }

  void log(const std::string& message);
private:
  Logger(const Logger& other);

  std::vector<std::string> logs_;
};


#define LOG_TO(logger, msg)               \
  do {                                    \
    try {                                 \
        (logger)->log((msg));              \
    } catch (const std::exception& e) {   \
    }                                     \
  } while (0)

#define LOG(msg) LOG_TO((logger()), msg)
