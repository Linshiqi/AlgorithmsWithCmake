#pragma once

#include <vector>
#include "StringSortBase.h"
#include "../sort/ElementarySort.h"
namespace code047 {
	class MSD : public StringSortBase{
	public:
		MSD() {}
		MSD(const MSD&) = delete;
		MSD& operator=(const MSD&) = delete;

		void sort(std::vector<std::string>& strings) override {
			size_t N = strings.size();
			aux.resize(N, "");
			_sort(strings, 0, strings.size(), 0);
		}
	private:
		void _sort(std::vector<std::string> &strings, size_t low, size_t high, size_t d);
		int charAt(std::string& strings, size_t d) {
			if (d >= strings.size()) {
				return -1;
			}
			else {
				return strings[d];
			}
		}
		const size_t M = 15;
		const size_t R = 256;
		std::vector<std::string> aux;

	};
}
