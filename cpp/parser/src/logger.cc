#include "logger.h"
#include "ctime"
#include "iostream"

void Logger::log(const std::string& message) const
{
  logs_.push_back(rawString(message));
};

void Logger::dump() const
{
  for (auto entry : logs_)
  {
    std::time_t now = std::time(nullptr);
    char timestamp[26];
    ctime_s(timestamp, sizeof timestamp, &now);
    std::string timestampWithoutEndl(timestamp);
    timestampWithoutEndl = timestampWithoutEndl.substr(0, 24);

    std::cout << timestampWithoutEndl << " " << entry << std::endl;
  }
}

std::string Logger::rawString(const std::string& text) const
{
  std::string result;
  for (auto c : text) {
    switch (c) {
    case '\'': result.append(R"(\')"); break;
    case '\"': result.append(R"(\")"); break;
    case '\?': result.append(R"(\?)"); break;
    case '\\': result.append(R"(\\)"); break;
    case '\a': result.append(R"(\a)"); break;
    case '\b': result.append(R"(\b)"); break;
    case '\f': result.append(R"(\f)"); break;
    case '\n': result.append(R"(\n)"); break;
    case '\r': result.append(R"(\r)"); break;
    case '\t': result.append(R"(\t)"); break;
    case '\v': result.append(R"(\v)"); break;
    default: result.push_back(c);
    }
  }

  return result;
}
