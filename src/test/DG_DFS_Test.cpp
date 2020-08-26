#include "../../include/catch.hpp"
#include "../graph/DirectedDFS.h"
#include <iostream>

using namespace code047;
TEST_CASE("directed graph test") {
	std::string tinyDG_file = "../data/tinyDG.txt";
	Digraph tinyDG(tinyDG_file);

	SECTION("1 has no paths to others") {
		DirectedDFS dg_dfs(tinyDG, 1);
		for (int i = 0; i < tinyDG.V(); i++) {
			if (dg_dfs.marked(i)) {
				std::cout << i << " " ;
			}
		}
		std::cout << std::endl;
	}
	SECTION("test 2 as source") {
		DirectedDFS dg_dfs(tinyDG, 2);
		for (int i = 0; i < tinyDG.V(); i++) {
			if (dg_dfs.marked(i)) {
				std::cout << i << " ";
			}
		}
		std::cout << std::endl;
	}
	SECTION("test 1¡¢2¡¢6 as sources") {
		std::vector<int> sources = { 1, 2, 6 };
		DirectedDFS dg_dfs(tinyDG, sources);
		for (int i = 0; i < tinyDG.V(); i++) {
			if (dg_dfs.marked(i)) {
				std::cout << i << " ";
			}
		}
		std::cout << std::endl;
	}

}