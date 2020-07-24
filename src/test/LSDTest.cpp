#include "../../include/catch.hpp"
#include "../string/LSD.h"
#include "../fileHelper/FileReader.h"
#include <algorithm>

using namespace code047;

TEST_CASE("LSD test") {
	SECTION("Read fixed length string from words5-knuth.txt") {

		std::vector<std::string> vstring;

		std::string file = "../data/words5-knuth.txt";
		vstring = FileReader::readLines(file);

		std::vector<std::string> vstringCpy(vstring);

		LSD::sort(vstring, 5);

		std::sort(vstringCpy.begin(), vstringCpy.end());
		
		for (size_t i = 0; i < vstring.size(); i++) {
			REQUIRE(vstring[i] == vstringCpy[i]);
		}
	}
}
