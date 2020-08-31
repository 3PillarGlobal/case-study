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

void Logger::print(std::ostream& output) const
{
    auto escaped_print = [&](const std::string& input) {
        for(const auto& value: input) {
            switch (value) {
                case '\a':  output << "\\a";    break;
                case '\b':  output << "\\b";    break;
                case '\f':  output << "\\f";    break;
                case '\n':  output << "\\n";    break;
                case '\r':  output << "\\r";    break;
                case '\t':  output << "\\t";    break;
                case '\v':  output << "\\v";    break;
                case '\\':  output << "\\\\";   break;
                case '\'':  output << "\\'";    break;
                case '\"':  output << "\\\"";   break;
                case '\?':  output << "\\\?";   break;
                default:    output << value;    break;
            }
        }
        output << "\n";
    };

    for(const auto& line: logs_) {
        escaped_print(line);
    }
}