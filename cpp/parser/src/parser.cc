#include <cctype>
#include <iostream>
#include "parser.h"

std::vector<std::string> Parser::parse(const std::string& text) const
{
  std::vector<std::string> parsingResult;
  std::string word;
  for(int i=0; i < text.size(); i++) {
    while(i < text.size() and !std::isspace(text[i])){
      word.push_back(text[i]);
      i++;
    }
    if(!word.empty()) {
      parsingResult.push_back(word);
      word.clear();
    }
  }

  return parsingResult;
};
