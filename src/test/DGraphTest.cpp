#include "../../include/catch.hpp"
#include "../graph/Digraph.h"

using namespace code047;

TEST_CASE("DG") {
	std::string tinyDG_file = "../data/tinyDG.txt";
	Digraph tinyDG(tinyDG_file);

	SECTION("Test V()") {
		REQUIRE(tinyDG.V() == 13);
	}
	SECTION("Test E()") {
		REQUIRE(tinyDG.E() == 22);
	}
	SECTION("Test adj") {
		std::vector<int> adjs = tinyDG.adj(6);
		REQUIRE(adjs.size() == 3);
		REQUIRE(std::find(adjs.begin(), adjs.end(), 0) != adjs.end());
		REQUIRE(std::find(adjs.begin(), adjs.end(), 4) != adjs.end());
		REQUIRE(std::find(adjs.begin(), adjs.end(), 9) != adjs.end());

	}
}
