#include "../../include/catch.hpp"
#include "../string/MSD.h"
#include "../fileHelper/FileReader.h"
#include <algorithm>
#include "../utils/util.hpp"

using namespace code047;

TEST_CASE("MSD test") {
	SECTION("Read fixed length string from words5-knuth.txt") {

		std::vector<std::string> vstring;

		std::string file = "../data/words5-knuth.txt";
		vstring = FileReader::readLines(file);

		std::vector<std::string> vstringCpy(vstring);

		MSD msd;
		msd.sort(vstring);
		//display(vstring);

		std::sort(vstringCpy.begin(), vstringCpy.end());
		
		for (size_t i = 0; i < vstring.size(); i++) {
			REQUIRE(vstring[i] == vstringCpy[i]);
		}
	}
	SECTION("Read fixed length string from MSD-worst.txt") {

		std::vector<std::string> vstring;

		std::string file = "../data/MSD-worst.txt";
		vstring = FileReader::readLines(file);

		std::vector<std::string> vstringCpy(vstring);

		MSD msd;
		msd.sort(vstring);
		//display(vstring);

		std::sort(vstringCpy.begin(), vstringCpy.end());
		
		for (size_t i = 0; i < vstring.size(); i++) {
			REQUIRE(vstring[i] == vstringCpy[i]);
		}
	}
}
