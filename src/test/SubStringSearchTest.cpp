#include "../../include/catch.hpp"
#include "../string/Kmp.h"
#include <memory>
using namespace code047;

TEST_CASE("���ַ�������") {
	std::string txt = "abfsdjfakdfladf";
	std::string pat = "fsdj";
	const size_t index = 2;
	std::shared_ptr<SubStringBase> s_ptr(new Kmp(127));
	SECTION("KMP") {
		s_ptr = std::make_shared<Kmp>(127);
		size_t res = s_ptr->search(txt, pat);
		REQUIRE(res == index);
	}
}
