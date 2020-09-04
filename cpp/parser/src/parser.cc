#include <cctype>
#include <iostream>
#include "parser.h"

std::vector<std::string> Parser::parse(const std::string& text) const
{
  std::vector<std::string> parsingResult;
  auto lam = [](unsigned char c) {return std::isspace(c);};
  auto it = find_if(text.begin(), text.end(), lam);
  auto curr = text.begin();
  auto addParseResult = [&]() {if (std::distance(curr, it) > 1)
                                 parsingResult.emplace_back(curr, it);};
  while (it!= text.end()) {
    curr= it;
    it = find_if(std::next(it), text.end(), lam);
    addParseResult();
  }
  addParseResult();
  LOG_TO(logger, "Parsed " + std::to_string(parsingResult.size()) + " words.");

  return parsingResult;
};
