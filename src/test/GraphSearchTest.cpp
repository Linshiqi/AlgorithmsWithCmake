#include "../../include/catch.hpp"
#include "../graph/DepthFirstSearch.h"
#include <memory>
#include <iostream>

using namespace code047;

TEST_CASE("graphSearch test") {
	SECTION("dfs") {
		Graph tinyG("../data/tinyG.txt");
		int s = 9;
		std::shared_ptr<GraphSearch> gs_ptr(new DepthFirstSearch(tinyG, s));
		for (int v = 0; v < tinyG.getV();v++) {
			if (gs_ptr->marked(v)) {
				std::cout << v << " ";
			}
		}
		std::cout << std::endl;

		if (tinyG.getV() != gs_ptr->count()) {
			std::cout << "Not";
		}
		std::cout << "connected" << std::endl;
	}
}
