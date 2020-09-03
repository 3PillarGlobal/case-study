#ifndef H_PARSER
#define H_PARSER

#include "loggable.h"

class Parser : public Loggable
{
public:
  explicit Parser(const std::shared_ptr<Logger>& logger = nullptr);
  std::vector<std::string> parse(const std::string& text) const;
};

#endif
