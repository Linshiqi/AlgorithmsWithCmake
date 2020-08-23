#include "../../include/catch.hpp"
#include "../string/TrieST.h"
#include <iostream>
using namespace code047;

TEST_CASE("TrieST") {
	std::shared_ptr<StringST<int>> s_ptr = std::make_shared<TrieST<int>>();
	std::vector<std::string> s_v = { "by", "sea", "sells", "she", "shells", "the" };
	int i = 1;

	for (auto s : s_v) {
		s_ptr->put(s, i);

		int size = s_ptr->size();
		REQUIRE(size == i);

		i++;
	}

	SECTION("CONTAIN") {
		for (int i = 0; i < s_v.size(); i++) {
			auto v = s_ptr->contains(s_v[i]);
			REQUIRE(v == true);
		}
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

			int size = s_ptr->size();
			REQUIRE(size == s_v.size()-i-1);
		}
	}

	SECTION("get all keys") {
		std::vector<std::string> res = s_ptr->keys();
		REQUIRE(res.size() == 6);
		for (int i = 0; i < res.size(); i++) {
			REQUIRE(res[i] == s_v[i]);
		}
	}
	SECTION("key with prefix") {
		std::string pre = "sh";
		std::vector<std::string> res = s_ptr->keysWithPrefix(pre);
		REQUIRE(res.size() == 2);
		REQUIRE(res[0] == "she");
		REQUIRE(res[1] == "shells");
	}

	SECTION("Whild match") {
		std::string pat = "*h*";
		std::vector<std::string> res = s_ptr->keysThatMatch(pat);
		REQUIRE(res.size() == 2);
		REQUIRE(res[0] == "she");
		REQUIRE(res[1] == "the");
	}
	
	SECTION("Longest Key that is prefix of string") {
		std::string s("shells");
		std::string res = s_ptr->longestKeyPrefixOf(s);
		REQUIRE(res == "shells");

		s = "shell";
		res = s_ptr->longestKeyPrefixOf(s);
		REQUIRE(res == "she");

	}
}