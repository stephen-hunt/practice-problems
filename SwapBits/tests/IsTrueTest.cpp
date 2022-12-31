#include <catch2/catch_test_macros.hpp>

#include "IsTrue.hpp"

TEST_CASE( "Is True", "[is true]" ) {
    IsTrue isTrue;
    REQUIRE(isTrue.isTrue() == true);
}