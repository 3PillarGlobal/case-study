#include "logger.h"
#include "iostream"

void Logger::log(const std::string& message) const
{
    try {
        logs_.push_back(message);
    } catch (const std::exception& e) {
        std::cout << "Logger error: " << e.what() << std::endl;
    }
};
