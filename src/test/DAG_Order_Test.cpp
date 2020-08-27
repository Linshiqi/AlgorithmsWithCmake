#include "../../include/catch.hpp"
#include "../graph/DGDFSOrder.h"
#include <iostream>
using namespace code047;

TEST_CASE("DAG order test") {
	std::string DAG_file = "../data/DAG.txt";
	Digraph tinyDG(DAG_file);
	
	DGDFSOrder dsfOrder(tinyDG);
	SECTION("preOrder") {
		std::vector<int> res = dsfOrder.getPreOrder();
		for (auto e : res) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	SECTION("postOrder") {
		std::vector<int> res = dsfOrder.getPostOrder();
		for (auto e : res) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	SECTION("reverseOrder") {
		std::vector<int> res = dsfOrder.getReversePostOrder();
		for (auto e : res) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}