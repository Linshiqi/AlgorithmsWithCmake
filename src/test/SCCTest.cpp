#include "../../include/catch.hpp"
#include "../graph/SCC.h"

using namespace code047;

TEST_CASE("SCC Test") {
	std::string tinyDG_file = "../data/tinyDG.txt";
	Digraph tinyDG(tinyDG_file);
	SCC scc(tinyDG);

	SECTION("count() TEST") {
		int count = scc.count();
		REQUIRE(count == 5);
	}

	SECTION("_id[1] == 0") {
		REQUIRE(scc.id(1) == 0);
	}

	SECTION("_id[6] == 3") {
		REQUIRE(scc.id(6) == 3);
	}

	SECTION("_id[4] == 1") {
		REQUIRE(scc.id(4) == 1);
	}

	SECTION("7, 8 is strongly connected") {
		bool res = scc.stronglyConnected(7, 8);
		REQUIRE(res == true);

		res = scc.stronglyConnected(7, 8);
		REQUIRE(res == true);

		res = scc.stronglyConnected(11, 4);
		REQUIRE(res == false);

		res = scc.stronglyConnected(9, 12);
		REQUIRE(res == true);
	}
}

