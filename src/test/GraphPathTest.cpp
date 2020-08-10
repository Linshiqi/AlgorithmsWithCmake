#include "../../include/catch.hpp"
#include "../graph/DepthFirstPaths.h"
#include "../graph/BreadthFirstPaths.h"
#include <string>

using namespace code047;

TEST_CASE("Path") {
	
	Graph tinyG("../data/tinyG.txt");
	int s = 0;

	Paths* p_ptr = nullptr;
	//p_ptr = new DepthFirstPaths(tinyG, s);
	p_ptr = new BreadthFirstPaths(tinyG, s);
	
	for (int i = 0; i < tinyG.getV();i++) {
		std::cout << s << " to " << i << " : ";
		if (p_ptr->hasPathTo(i)) {
			for (int v : p_ptr->pathTo(i)) {
				if (v == s) {
					std::cout << s;
				}
				else {
					std::cout << "->" << v;
				}
			}
		}
		std::cout << std::endl;
	}
	delete p_ptr;
}
