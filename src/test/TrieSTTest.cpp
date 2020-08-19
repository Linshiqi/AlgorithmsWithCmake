#include "../../include/catch.hpp"
#include "../string/TrieST.h"
using namespace code047;

TEST_CASE("TrieST") {
	std::shared_ptr<StringST<int>> s_ptr = std::make_shared<TrieST<int>>();
	std::vector<std::string> s_v = { "by", "sea", "sells", "she", "shells", "the" };
	int i = 1;

	SECTION("PUT") {
		for (auto s : s_v) {
			s_ptr->put(s, i);
			i++;
		}

		SECTION("GET") {
			for (int i = 0; i < s_v.size(); i++) {
				auto v = s_ptr->get(s_v[i]);
				REQUIRE(*v == i+1);
			}
		}

		SECTION("DELETE") {
			for (int i = 0; i < s_v.size(); i++) {
				s_ptr->deleteKey(s_v[i]);
				auto v = s_ptr->get(s_v[i]);
				REQUIRE(v == nullptr);
			}
		}
	}
	
}