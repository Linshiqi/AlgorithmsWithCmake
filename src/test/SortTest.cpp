#include "../../include/catch.hpp"
#include "../sort/SortBase.h"
#include "../sort/BasicSort.h"
#include <memory>

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
void f(std::shared_ptr<SortBase<int>> &sb_ptr, std::vector<int> &a) {
	sb_ptr->sort(a);
	bool isSorted = sb_ptr->isSorted(a);
	REQUIRE(isSorted == true);
}
TEST_CASE("InsertSort test") {
	
	std::vector<int> a = { 1,5,6,3,8,9,12,32,15,23,22,11,66 };
	SECTION("insertSort test") {
		std::shared_ptr<SortBase<int>> sb_ptr(new InsertSort<int>()); //this line code would reporting error "cannot instaniate abstract class, why?"
		f(sb_ptr, a);
	}
	SECTION("selectSort test") {
		std::shared_ptr<SortBase<int>> sb_ptr(new SelectSort<int>()); //this line code would reporting error "cannot instaniate abstract class, why?"
		f(sb_ptr, a);
	}
}

