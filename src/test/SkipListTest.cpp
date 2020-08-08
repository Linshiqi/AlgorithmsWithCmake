#include "../../include/catch.hpp"
#include "../graph/SkipList.h"
#include <string>
using namespace code047;

TEST_CASE("SkipList Test") {
	SECTION("add test") {
		SkipList<int, std::string> students(-1, "", 2);
		students.add(26, "lsq");
		students.add(30, "hcr");

		SECTION("contain test") {
			bool res = students.contains(26);
			REQUIRE(res);
			REQUIRE(students.contains(27) == false);
			REQUIRE(students.contains(30) == true);
		}
	}
}