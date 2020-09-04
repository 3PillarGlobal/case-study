#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "parser.h"
#include "logger.h"
#include <memory>


TEST_CASE( "Parser for empty string", "[dummy]" ) {
  std::unique_ptr<Logger> logger(new Logger());
  Parser parser(std::move(logger));
  auto result = parser.parse(std::string());
  REQUIRE( result.empty() );
}

TEST_CASE( "splitting", "[dummy]" ) {
  std::unique_ptr<Logger> logger(new Logger());
  Parser parser(std::move(logger));

  auto result = parser.parse("fjpwei iewhow oqeigrwo owio");
  REQUIRE( result.size() == 4);
  result = parser.parse(R"(fjpwei  iewhow  oqeigrwo  owio)");
  REQUIRE( result.size() == 4);
  result = parser.parse("fjpweiiewhowoqeigrwoowio)");
  REQUIRE( result.size() == 1);
  result = parser.parse("\t\n\f\r\v ");
  REQUIRE( result.size() == 0);
}

TEST_CASE( "isspace special cases", "[dummy]" ) {
  std::unique_ptr<Logger> logger(new Logger());
  Parser parser(std::move(logger));

  auto result = parser.parse("ÃÆÑ lkhgjldhsÑÑÑÑÑÑÑlkjg ƋƋƋƋÃÆÑƋ");
  REQUIRE( result.size() == 3);
  result = parser.parse("ÃÆÑƱƱƱƱƋƋÃÆÑƋ");
  REQUIRE( result.size() == 1);
}
