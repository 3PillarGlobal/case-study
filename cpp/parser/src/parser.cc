#include <cctype>
#include <iostream>
#include <sstream>
#include "parser.h"


std::vector<std::string> Parser::parse(const std::string& text) const
{
  LOG("Starting parse.");
  std::vector<std::string> parsingResult;
  std::string word;
  // declare outside of for just for logging purposes
  int i = 0;
  int textSize = text.size();
  for(;i < textSize; i++) {
    // here we need to stay inside the bounds of the vector
    while(i < textSize && !std::isspace(text[i])){
      word.push_back(text[i]);
      i++;
    }
    if(!word.empty()) {
      parsingResult.push_back(word);
      word.clear();
    }
  }
  LOG_STREAM("Parsed " << parsingResult.size() << " words from a string of " << text.size() << " characters. Parsed up to " << (i - 1) << ".");

  return parsingResult;
};
