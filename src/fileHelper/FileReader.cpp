#include "FileReader.h"
namespace code047 {
	std::vector<std::string> FileReader::readLines(std::string file) {
		std::vector<std::string> res;
		if (file.empty()) {
			return  res;
		}
		std::ifstream ifst(file);
		try {
			if (ifst.is_open() && ifst.good()) {
				std::string line;
				while (std::getline(ifst, line)) {
					res.push_back(line);
				}
			}
			else {
				std::cout << "Open file " << file << "failed" << std::endl;
			}
			ifst.close();
		}
		catch (const std::exception e) {
			std::cout << e.what() << std::endl;
			if (ifst.is_open()) {
				ifst.close();
			}
		}
		return res;
	}
	std::vector<int> FileReader::getVertexPair(std::string s)
	{
		std::vector<int> res;
		std::istringstream iss(s);
		std::string vString("");
		while (iss >> vString) {
			res.push_back(std::stoi(vString));
		}
		return res;
	}
}
