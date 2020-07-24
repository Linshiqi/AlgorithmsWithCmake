#include "LSD.h"

namespace code047 {

	/// <summary>
	/// 时间复杂度：O(WN+WR) ~ O(WN) 
	///			   其中W为字符串长度，R为字符集个数都可视为常数，
	///			   所以LSD字符串排序算法时间复杂度为线性
	/// 空间复杂度：O(R+N)~O(N) 使用了aux数组N个元素及count数组R个元素
	/// </summary>
	/// <param name="strings"></param>
	/// <param name="w"></param>
	void LSD::sort(std::vector<std::string>& strings, const int& w) {
		const int R = 256;		// Enough for ASCII characters
		std::vector<std::string> aux(strings.size());

		// Sort strings from left to right using count sort algorithm
		for (int i = w - 1; i >= 0; i--) {
			std::vector<int> count(R + 1, 0);

			// Frequency count
			for (int j = 0; j < strings.size(); j++) {
				count[strings[j][i] + 1]++;
			}

			// Turn frequency to index in sorted array
			for (int j = 1; j < R; j++) {
				count[j] += count[j - 1];
			}

			// Copy elements to aux with index in count 
			for (int j = 0; j < strings.size(); j++) {
				aux[count[strings[j][i]]++] = strings[j];
			}

			// Copy back
			for (int j = 0; j < strings.size(); j++) {
				strings[j] = aux[j];
			}
		}
	}
}



