#ifndef H_PARSER
#define H_PARSER

#include "loggable.h"

class Parser : public Loggable
{
public:
  std::vector<std::string> parse(const std::string& text) const;
};

#endif
