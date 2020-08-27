#include "../../include/catch.hpp"
#include "../graph/DAGTopoSort.h"
#include <iostream>
using namespace code047;

TEST_CASE("directed graph topological sort") {
	std::string DAG_file = "../data/DAG.txt";
	Digraph dag(DAG_file);

	SECTION("graph has no cycle") {
		DAGTopoSort dgtpSort(dag);
		REQUIRE(dgtpSort.isDAG() == true);

		for (auto i : dgtpSort.topoOrder()) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}

TEST_CASE("directed graph with cycle") {
	std::string tinyDG_file = "../data/tinyDG.txt";
	Digraph tinyDG(tinyDG_file);

	DAGTopoSort dtps(tinyDG);
	REQUIRE(dtps.isDAG() == false);
}