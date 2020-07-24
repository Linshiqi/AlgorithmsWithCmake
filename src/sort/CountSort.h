/******************************************************************************
Function:			Count sort algorithm 

Time complexity :	O(RN)
					R represents the number of all possible value in array to be sorted
					N represents the total number of elements in array 
					So, count sort algorithm is linear sort algorithm that efficiently for small R

Space complexity:	O(N+R)
					O(N) for aux array, and O(R) for count array

Author:				Code047

Date:				2020/07/24
*******************************************************************************/
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

namespace code047 {
	template<typename T>
	class CountSort {
	public:
		CountSort() = default;
		~CountSort() {};
		/// <summary>
		/// Return minimum value in array if it's not empty,
		/// Or return INT_MIN.
		/// </summary>
		/// <param name="array"></param>
		/// <returns>minimum value in array or INT_MIN</returns>
		static void sort(std::vector<T>& array);
	private:
	};

	/// <summary>
	/// Sort given array by count sort algorithm
	///
	/// Warning: the number of different elements in array should be less than 100,
	///			 in other words, the max element - min element should be less than 100
	/// </summary>
	/// <param name="array">array to sort</param>
	template<typename T>
	void CountSort<T>::sort(std::vector<T>& array) {
		// Count frequency
		const int max_diff_number = 100 + 1;
		//auto min_it = getMin(array);
		//auto max_it = getMax(array);
		auto max_it = std::max_element(std::begin(array), std::end(array));
		auto min_it = std::min_element(array.begin(), array.end());
		if (min_it == array.end() || max_it == array.end()) {
			return;
		}
		const int num = *max_it - *min_it + 1;
		if (num > max_diff_number - 1) {
			std::cout << "out of range, aborting" << std::endl;
			abort();
		}
		std::vector<size_t> count(max_diff_number, 0);

		for (auto it = array.begin(); it != array.end(); it++) {
			count[*it - *min_it + 1]++; // Normalize array by - min
		}

		// Turn frequency to sorted array index
		for (int i = 1; i < count.size(); i++) {
			count[i] += count[i - 1];
		}

		// Sort array by count
		std::vector<int> aux(array.size());
		for (size_t i = 0; i < array.size(); i++) {
			aux[count[array[i] - *min_it]++] = array[i];
		}

		// Copy back to array
		for (size_t i = 0; i < aux.size(); i++) {
			array[i] = aux[i];
		}

	}
}




