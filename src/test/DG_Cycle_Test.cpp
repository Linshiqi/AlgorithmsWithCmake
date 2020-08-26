#include "../../include/catch.hpp"
#include "../graph/DirectedCycle.h"
#include <iostream>
using namespace code047;

TEST_CASE("Directed Graph Cycle Test") {
	std::string tinyDG_file = "../data/tinyDG.txt";
	Digraph tinyDG(tinyDG_file);

	DirectedCycle dc(tinyDG);

	SECTION("hasCycle is true") {
		REQUIRE(dc.hasCycle() == true);
	}

	SECTION("print out cycle") {
		auto res = dc.getCycleVectices();
		for (auto e : res) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}
