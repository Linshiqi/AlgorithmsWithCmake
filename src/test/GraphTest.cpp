#include "../../include/catch.hpp"
#include "../graph/Graph.h"
#include "../fileHelper/FileReader.h"

using namespace code047;

TEST_CASE("Graph test") {
	SECTION("Read graph from file") {
		Graph tinyG("../data/tinyG.txt");
		
		SECTION("Test getV()") {
			REQUIRE(tinyG.getV() == 13);
		}
		SECTION("Test getE()") {
			REQUIRE(tinyG.getE() == 13);
		}
		SECTION("Test adj()") {
			std::vector<int> adjs = tinyG.adj(3);
			REQUIRE(adjs[0] == 4);
			REQUIRE(adjs[1] == 5);
		}
		SECTION("Test static degree()") {
			int dgr = Graph::degree(tinyG, 9);
			REQUIRE(dgr == 3);
		}
		SECTION("Test static maxDegree()") {
			int maxDgr = Graph::maxDegree(tinyG);
			REQUIRE(maxDgr == 4);
		}
		SECTION("Test static avgDegree()") {
			int avgDgr = Graph::avgDegree(tinyG);
			REQUIRE(avgDgr == 2);
		}
		SECTION("Test numberofSelfLoops()") {
			int selfLoops = Graph::numberOfSelfLoops(tinyG);
			REQUIRE(selfLoops == 0);
		}
	}
}