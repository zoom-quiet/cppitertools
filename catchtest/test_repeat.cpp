#include <repeat.hpp>

#include "helpers.hpp"

#include <vector>
#include <string>
#include <iterator>

#include "catch.hpp"

using iter::repeat;

TEST_CASE("repeat: one argument keeps giving value back", "[repeat]") {
    auto r = repeat('a');
    auto it = std::begin(r);
    REQUIRE( *it == 'a' );
    ++it;
    REQUIRE( *it == 'a' );
    ++it;
    REQUIRE( *it == 'a' );
    ++it;
    REQUIRE( *it == 'a' );
    ++it;
    REQUIRE( *it == 'a' );
}

TEST_CASE("repeat: two argument repeats a number of times", "[repeat]") {
    auto r = repeat('a', 3);
    std::string s(std::begin(r), std::end(r));
    REQUIRE( s == "aaa" );
}

TEST_CASE("repeat: 0 count gives empty sequence", "[repeat]") {
    auto r = repeat('a', 0);
    REQUIRE( std::begin(r) == std::end(r) );
}
