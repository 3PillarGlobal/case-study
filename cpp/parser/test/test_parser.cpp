#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "parser.h"


TEST_CASE( "Parser for empty string", "[dummy]" ) {
  Parser parser;

  auto result = parser.parse(std::string());

    REQUIRE( result.empty() );
}

TEST_CASE( "splitting", "[dummy]" ) {
  std::shared_ptr<Logger> logger(new ConsoleLogger);
  Parser parser(logger);

  auto result = parser.parse("fjpwei iewhow oqeigrwo owio");
  REQUIRE( result.size() == 4);
  result = parser.parse(R"(fjpwei  iewhow  oqeigrwo  owio)");
  REQUIRE( result.size() == 4);
  result = parser.parse("fjpweiiewhowoqeigrwoowio)");
  REQUIRE( result.size() == 1);
  result = parser.parse("\t\n\f\r\v ");
  REQUIRE( result.size() == 0);
}
