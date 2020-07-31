#include "MSD.h"

namespace code047 {
	void MSD::_sort(std::vector<std::string> &strings, size_t low, size_t high, size_t d) {
		if (high < low + M) {
			InsertSort<std::string> is;
			std::vector<std::string> tmp(strings.begin()+low, strings.begin()+high);
			is.sort(tmp);
		}
		size_t N = strings.size();
		aux.resize(N,0);
		std::vector<size_t> count(R + 2, 0);
		// Count frequency
		for (size_t i = low; i < high; i++) {
			(count[charAt(strings[i], d) + 2])++;
		}

		// Frequency to index
		for (size_t i = 1; i < R+1; i++) {
			count[i] += count[i - 1];
		}

		// Distribute
		for (size_t i = low; i < high; i++) {
			aux[count[charAt(strings[i], d) + 1]++] = strings[i];
		}
		
		// Copy Back
		for (size_t i = low; i < high;i++) {
			strings[i] = aux[i - low];
		}

		// Recursively sort each character value
		for (size_t i = 0; i < R; i++) {
			_sort(strings, count[i], count[i + 1], d + 1);
		}
	}
}