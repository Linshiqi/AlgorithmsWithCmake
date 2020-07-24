#include "../../include/catch.hpp"
#include "../sort/CountSort.h"
#include <algorithm>

using namespace code047;

TEST_CASE("countSort test") {
	SECTION("basic") {
		std::vector<int> a = { 5,5,8,6,7,3,5,1,10,9,2,8,7 };
		std::vector<int> aCopy(a);
		std::vector<int> b = { 2, 0, 1 };
		std::vector<int> bCopy(b);
		std::sort(aCopy.begin(), aCopy.end());
		std::sort(bCopy.begin(), bCopy.end());
		

		CountSort<int>::sort(b);
		for (size_t i = 0; i < b.size(); i++) {
			REQUIRE(b[i] == bCopy[i]);
		}

		CountSort<int>::sort(a);
		for (size_t i = 0; i < a.size(); i++) {
			REQUIRE(a[i] == aCopy[i]);
		}

	}
}
