#include <cctype>
#include <iostream>
#include "parser.h"

std::vector<std::string> Parser::parse(const std::string& text) const
{
  std::vector<std::string> parsingResult;
  std::string word;
  for (int i = 0; i < text.size(); i++) {
    while (i < text.size() && !std::isspace(text[i])) {
      word.push_back(text[i]);
      i++;
    }
    if (!word.empty()) {
      parsingResult.push_back(word);
      word.clear();
    }
  }

  // Logging point for parser result
  if (!parsingResult.empty()) {
    LOG("Parser finished successfuly; input <" + text + "> has " + std::to_string(parsingResult.size()) + " words.");
  }
  else {
    LOG("Parser failed; input <" + text + "> is either empty or illformed and cannot be parsed.");
  }

  return parsingResult;
}

void Parser::dumpLogs() const
{
  DUMP_LOGS();
}
