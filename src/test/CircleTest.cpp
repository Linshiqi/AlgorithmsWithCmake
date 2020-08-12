#include "../../include/catch.hpp"
#include "../graph/Circle.h"

using namespace code047;
TEST_CASE("Circle") {
	SECTION("has circle") {
		Graph tinyG("../data/tinyG.txt");
		Circle cc(tinyG);
		bool b = cc.hasCircle();
		REQUIRE(b == true);
	}
	SECTION("no circle") {
		Graph tinyG("../data/noCircle.txt");
		Circle cc(tinyG);
		bool b = cc.hasCircle();
		REQUIRE(b == false);
	}
	
}