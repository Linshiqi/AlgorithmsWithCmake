#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
namespace code047 {
	class FileReader
	{
	public:
		static std::vector<std::string> readLines(std::string file);
		static std::vector<int> getVertexPair(std::string s);
	};
}


