#ifndef H_PARSER
#define H_PARSER

#include "logger.h"

class Parser
{
public:
  Parser(std::unique_ptr<Logger> logger):logger(std::move(logger)) {}//++
  std::vector<std::string> parse(const std::string& text) const;
  std::unique_ptr<Logger> logger;
};

#endif
