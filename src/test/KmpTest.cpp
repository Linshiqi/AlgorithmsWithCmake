#include "../../include/catch.hpp"
#include "../string/Kmp.h"
#include <memory>
using namespace code047;
TEST_CASE("SubString search") {
	std::shared_ptr<SubStringBase> s_subS;
	const int R = 127;
	std::string txt = "hello world lsq";
	std::string pat = "world";

	std::string txt2 = "ababcdfsdfac";
	SECTION("KMP") {
		s_subS = std::make_shared<Kmp>(R);

		int res = s_subS->search(txt, pat);
		REQUIRE(res == 6);
	}
}