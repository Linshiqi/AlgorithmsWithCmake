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

		SECTION("get test") {
			std::string name = *(students.get(26));
			REQUIRE(name == "lsq");
			name = *(students.get(30));
			REQUIRE(name == "hcr");
		}

		SECTION("delete 26 test") {
			size_t old_h = students.height();
			students.deleteKey(26);
			REQUIRE(students.contains(26) == false);
			REQUIRE(students.contains(30) == true);
			REQUIRE(students.height() == old_h);
		}
		SECTION("delete 30 test, height-1") {
			size_t old_h = students.height();
			students.deleteKey(30);
			REQUIRE(students.contains(30) == false);
			REQUIRE(students.contains(26) == true);
			REQUIRE(students.height() == old_h-1);
		}
	}
}