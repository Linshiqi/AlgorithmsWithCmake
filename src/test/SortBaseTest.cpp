#include "../../include/catch.hpp"
#include "../sort/SortBase.h"

using namespace code047;

TEST_CASE("SortBase test") {
	SECTION("less() Test") {
		bool less = SortBase<int>::less(1, 2);
		REQUIRE(less == true);

		less = SortBase<int>::less(2, 1);
		REQUIRE(less == false);
	}
	SECTION("isSorted Test") {
		std::vector<int> a = { 1, 2, 3 };
		bool isSorted = SortBase<int>::isSorted(a);
		REQUIRE(isSorted == true);

		a = { 2,1,3 };
		isSorted = SortBase<int>::isSorted(a);
		REQUIRE(isSorted == false);
	}
}