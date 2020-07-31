#include "LSD.h"

namespace code047 {

	/// <summary>
	/// Time complexity :(WN+WR) ~ O(WN) 
	/// Space complexity:O(R+N)~O(N) 
	/// </summary>
	/// <param name="strings"></param>
	/// <param name="w"></param>
	void LSD::sort(std::vector<std::string>& strings, const size_t& w) {
		std::vector<std::string> aux(strings.size());
		// Sort strings from left to right using count sort algorithm
		for (size_t i = w - 1; i >= 0; i--) {
			std::vector<int> count(R + 1, 0);

			// Frequency count
			for (size_t j = 0; j < strings.size(); j++) {
				count[strings[j][i] + 1]++;
			}

			// Turn frequency to index in sorted array
			for (size_t j = 1; j < R; j++) {
				count[j] += count[j - 1];
			}

			// Copy elements to aux with index in count 
			for (size_t j = 0; j < strings.size(); j++) {
				aux[count[strings[j][i]]++] = strings[j];
			}

			// Copy back
			for (size_t j = 0; j < strings.size(); j++) {
				strings[j] = aux[j];
			}
		}
	}
}



