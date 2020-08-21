#include "../../include/catch.hpp"
#include "../string/BruteForce.h"
#include <memory>
using namespace code047;


TEST_CASE("brute force search") {
	std::string txt = "abcab";
	std::string pat = "cab";

	const size_t N = txt.length();

	std::shared_ptr<SubStringSearch> ss_ptr;
	SECTION("found") {
		ss_ptr = std::make_shared<BruteForce>();
		size_t res = ss_ptr->searchFirstOccurrence(txt, pat);
		REQUIRE(res == 2);

		pat = "bca";
		res = ss_ptr->searchFirstOccurrence(txt, pat);
		REQUIRE(res == 1);

		pat = "abc";
		res = ss_ptr->searchFirstOccurrence(txt, pat);
		REQUIRE(res == 0);
	}

	SECTION("not found") {
		ss_ptr = std::make_shared<BruteForce>();
		pat = "cad";
		size_t res = ss_ptr->searchFirstOccurrence(txt, pat);
		REQUIRE(res == N);
	}
}
