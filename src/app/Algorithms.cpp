#include <iostream>
#include <stdexcept>
#include <limits>
#include <typeinfo>
#include "../graph/Graph.h"
#include "../sort/CountSort.h"
#include "../string/LSD.h"
#include "../fileHelper/FileReader.h"

using namespace code047;

template<typename T>
void display(std::vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl;
	}
}

void MyFunc(int c) {
	if (c > std::numeric_limits<char>::max()) {
		throw std::invalid_argument("MyFunc argument too large.");
	}
}

template<typename T>
void printSizeOfType(T& t) {
	std::cout << typeid(t).name() << " " << sizeof(t) << std::endl;
}

int main() {
	Graph tinyG("../data/tinyG.txt");
	std::cout << tinyG.toString() << std::endl;
	return 0;
}