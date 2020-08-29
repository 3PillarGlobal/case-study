#ifndef H_PARSER
#define H_PARSER

#include "loggable.h"

class Parser : public Loggable
{
public:
  // Ctor
  Parser()
    : Loggable(new Logger())
  {}

  std::vector<std::string> parse(const std::string& text) const;
  void dumpLogs() const;
};

#endif
