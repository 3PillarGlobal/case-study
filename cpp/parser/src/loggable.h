#pragma once

#include <memory>
#include "logger.h"

class Loggable
{
public:

  explicit Loggable(const std::shared_ptr<Logger>& logger = nullptr): logger_(logger) {}

  const Logger& logger() const
  {
    if (auto tempLogger = logger_.lock()) {
      return *tempLogger;
    }
  }

  template<typename... Type>
  void log(Type&&... args) const;

private:
  std::weak_ptr<Logger> logger_;
};

template<typename... Type>
void Loggable::log(Type&&... args) const
{
  if(auto tempLogger = logger_.lock()) {
    tempLogger->log<Type...>(std::forward<Type>(args)...);
  }
}

