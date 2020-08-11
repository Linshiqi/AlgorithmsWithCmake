#include "../../include/catch.hpp"
#include "../graph/CC.h"
#include <memory>

using namespace code047;
TEST_CASE("CC") {
	Graph tinyG("../data/tinyG.txt");
	std::shared_ptr<CC> cc_ptr = std::make_shared<CC>(tinyG);

	int M = cc_ptr->count();

	SECTION("test count") {
		REQUIRE(M == 3);
	}
	
	SECTION("test components") {
		std::vector<std::vector<int>> components(M);
		for (int i = 0; i < tinyG.getV(); i++) {
			components[cc_ptr->id(i)].push_back(i);
		}

		for (auto component : components) {
			for (int v : component) {
				std::cout << v << " ";
			}
			std::cout << std::endl;
		}
	}

}