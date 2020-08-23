#include "../../include/catch.hpp"
#include "../graph/TwoColor.h"

using namespace code047;

TEST_CASE("TwoColor") {
	Graph tinyG("../data/tinyG.txt");
	TwoColor tc(tinyG);
	std::cout << tc.isBipartite() << std::endl;
}