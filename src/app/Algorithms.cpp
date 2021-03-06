//#include <iostream>
//#include <stdexcept>
//#include <limits>
//#include <typeinfo>
//#include <string>
////#include "../graph/Graph.h"
//#include "../sort/CountSort.h"
//#include "../sort/ElementarySort.h"
//#include "../string/LSD.h"
//#include "../fileHelper/FileReader.h"
//#include "../string/MSD.h"
////#include "../utils/util.hpp"
//#include <chrono>
//#include <memory>
//#include <algorithm>
//
//#include "../graph/SkipList.h"
#include "../graph/SymbolGraph.h"
#include "../graph/BreadthFirstPaths.h"
#include "../string/TrieST.h"
#include "../sort/MergeSort.h"
#include "../sort/QuickSort.h"
using namespace code047;



//void MyFunc(int c) {
//	if (c > std::numeric_limits<char>::max()) {
//		throw std::invalid_argument("MyFunc argument too large.");
//	}
//}
//
//template<typename T>
//void printSizeOfType(T& t) {
//	std::cout << typeid(t).name() << " " << sizeof(t) << std::endl;
//}
//
//void graphTest() {
//	Graph tinyG("../data/tinyG.txt");
//	std::cout << tinyG.toString() << std::endl;
//}
//
//void sortArray(const std::shared_ptr<SortBase<int>>sb_ptr) {
//	//std::vector<int> a = { 1,5,6,3,8,9,12,32,15,23,22,11,66 };
//	std::vector<int> a;
//	for (int i = 0; i < 20000; i++) {
//		int rand = (int)getRandInRange(0, 10000);
//		a.push_back(rand);
//	}
//
//	std::cout << "-----------------"<< typeid(*sb_ptr).name() <<"----------------" << std::endl;
//	auto start = std::chrono::steady_clock::now();
//	sb_ptr->sort(a);
//	auto end = std::chrono::steady_clock::now();
//	std::chrono::duration<double, std::milli> elapsed = end - start;
//	std::cout << "sort array in " << elapsed.count() << "miniseconds" << std::endl;
//
//	display(a);
//}
//
//void elementarySortTest() {
//	std::shared_ptr<SortBase<int>> sb_ptr(new SelectSort<int>());
//	sortArray(sb_ptr);
//	sb_ptr = std::make_shared<InsertSort<int>>();
//	sortArray(sb_ptr);
//	sb_ptr = std::make_shared<ShellSort<int>>();
//	sortArray(sb_ptr);
//}
//
//void sortStrings() {
//	std::vector<std::string> strings = { "hello", "zhou", "lin", "liu", "li","zhan" };
//	std::shared_ptr<SortBase<std::string>> sb_ptr(new InsertSort<std::string>());
//	sb_ptr->sort(strings);
//
//	display(strings);
//}
//
//void msdSortTest() {
//	std::vector<std::string> strings = { "hello", "zhou", "lin", "liu", "zhan",
//										 "zhao","qian","sun","li","zhou",
//	                                     "wu","zhen","wang","lv","ya",
//	                                     "lucy","namei","joba","suolong","shanzhi",
//									     "aargh", "abash", "abaer", "abba", "abaar"};
//	std::vector<std::string> cpString(strings.begin(), strings.end());
//
//	std::shared_ptr<StringSortBase> ss_ptr(new MSD());
//	ss_ptr->sort(strings);
//	display(strings);
//	std::cout << "----------std sort-------------" << std::endl;
//	std::sort(cpString.begin(), cpString.end());
//	display(cpString);
//}
//
//void testVector() {
//	std::vector<std::string> tmp;
//	tmp.resize(10);
//}
//
//void testString() {
//	std::string a = "hell";
//	std::cout << a.size() << std::endl;
//}
//
//void testSkipList() {
//	SkipList<int, std::string> students(-1, "", 2);
//	students.add(26, "lsq");
//	students.add(30, "hcr");
//	std::string name = *(students.get(26));
//	std::cout << name << std::endl;
//	name = *(students.get(30));
//	std::cout << name << std::endl;
//}

void testSymbolGraph() {
	std::string routeFile = "../data/routes.txt";
	std::string movieFile = "../data/movies.txt";
	SymbolGraph sg(movieFile, "/");

	Graph G = sg.G();
	std::string searchKey;
	std::cout << "Enter key to search: ";
	while (searchKey != "q") {
		std::getline(std::cin, searchKey);
		for (int w : G.adj(sg.index(searchKey))) {
			std::cout << "    " << sg.name(w) << std::endl;
		}
	}
}

void degreesOfSeparation() {
	std::string routeFile = "../data/routes.txt";
	std::string movieFile = "../data/movies.txt";
	//SymbolGraph sg(movieFile, "/");
	SymbolGraph sg(routeFile, " ");

	Graph G = sg.G();
	std::string searchKey;

	std::string source;
	std::cout << "Enter source:";
	std::cin >> source;

	std::cout << "Enter key to search: ";
	while (searchKey != "q") {
		std::getline(std::cin, searchKey);
		int v = sg.index(searchKey);
		if (v == -1) {
			std::cout << "searchKey not in graph" << std::endl;
			continue;
		}
		BreadthFirstPaths path(G, sg.index(source));
		if (path.hasPathTo(v)) {
			for (int w : path.pathTo(v)) {
				std::cout << "    "<< sg.name(w) << " " << std::endl;
			}
		}

	}
}

void testTrieST() {
	std::shared_ptr<StringST<int>> s_ptr = std::make_shared<TrieST<int>>();
	std::vector<std::string> s_v = { "by", "sea", "sells", "she", "shells", "the" };
	int i = 1;
	for (auto s : s_v) {
		s_ptr->put(s, i);
		i++;
	}

}

void testMergeSort() {
	std::vector<int> a = { 1,5,6,3,8,9,12,32,15,23,22,11,66 };
	MergeSort<int> ms;
	ms.sort(a);
	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void testQuickSort() {
	std::vector<int> a = { 1,5,6,3,8,9,12,32,15,23,22,11,66 };
	QuickSort<int> qs;
	qs.sort(a);
	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main() {
	//elementarySortTest();
	//sortStrings();
	//msdSortTest();
	//testVector();
	//testString();
	//testSkipList();
	//testSymbolGraph();
	//degreesOfSeparation();
	//testTrieST();
	//testMergeSort();
	testQuickSort();
	return 0;
}