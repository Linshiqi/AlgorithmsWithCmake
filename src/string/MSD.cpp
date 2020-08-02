#include "MSD.h"
#include <algorithm>

namespace code047 {
	void MSD::_sort(std::vector<std::string> &strings, size_t low, size_t high, size_t d) {
		if (high < low + M) {
			InsertSort<std::string> is;
			is.sort(strings, low, high);
			return;
		}
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
			_sort(strings, low + count[i], low + count[i + 1], d + 1);
		}
	}
}