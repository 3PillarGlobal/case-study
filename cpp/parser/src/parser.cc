#include <vector>
#include "parser.h"

Parser::Parser(const std::shared_ptr<Logger> &logger) : Loggable(logger)
{
}

std::vector<std::string> Parser::parse(const std::string& text) const
{
  std::vector<std::string> parsingResult;
  std::string word;
  for(size_t i=0; i < text.size(); i++) {
    while(i < text.size() && !std::isspace(text[i])){
      word.push_back(text[i]);
      i++;
    }
    if(!word.empty()) {
      parsingResult.push_back(word);
      word.clear();
    }
  }

  log("parsed", parsingResult.size(), "words in [", text,"]");

  return parsingResult;
}
