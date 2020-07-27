#include "LSD.h"

namespace code047 {

	/// <summary>
	/// ʱ�临�Ӷȣ�O(WN+WR) ~ O(WN) 
	///			   ����WΪ�ַ������ȣ�RΪ�ַ�������������Ϊ������
	///			   ����LSD�ַ��������㷨ʱ�临�Ӷ�Ϊ����
	/// �ռ临�Ӷȣ�O(R+N)~O(N) ʹ����aux����N��Ԫ�ؼ�count����R��Ԫ��
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



