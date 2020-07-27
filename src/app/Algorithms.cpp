#include <iostream>
#include <stdexcept>
#include <limits>
#include <typeinfo>
#include <string>
#include "../graph/Graph.h"
#include "../sort/CountSort.h"
#include "../sort/ElementarySort.h"
#include "../string/LSD.h"
#include "../fileHelper/FileReader.h"
#include "../utils/util.hpp"
#include <chrono>

using namespace code047;



void MyFunc(int c) {
	if (c > std::numeric_limits<char>::max()) {
		throw std::invalid_argument("MyFunc argument too large.");
	}
}

template<typename T>
void printSizeOfType(T& t) {
	std::cout << typeid(t).name() << " " << sizeof(t) << std::endl;
}

void graphTest() {
	Graph tinyG("../data/tinyG.txt");
	std::cout << tinyG.toString() << std::endl;
}

void sortArray(const std::shared_ptr<SortBase<int>>sb_ptr) {
	//std::vector<int> a = { 1,5,6,3,8,9,12,32,15,23,22,11,66 };
	std::vector<int> a;
	for (int i = 0; i < 20000; i++) {
		int rand = getRandInRange(0, 10000);
		a.push_back(rand);
	}

	std::cout << "-----------------"<< typeid(*sb_ptr).name() <<"----------------" << std::endl;
	auto start = std::chrono::steady_clock::now();
	sb_ptr->sort(a);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "sort array in " << elapsed.count() << "miniseconds" << std::endl;

	display(a);
}

void elementarySortTest() {
	std::shared_ptr<SortBase<int>> sb_ptr(new SelectSort<int>());
	sortArray(sb_ptr);
	sb_ptr = std::make_shared<InsertSort<int>>();
	sortArray(sb_ptr);
	sb_ptr = std::make_shared<ShellSort<int>>();
	sortArray(sb_ptr);
}

int main() {
	elementarySortTest();
	return 0;
}