#pragma once

#include "SortBase.h"

namespace code047 {
	/// <summary>
	/// InsertSort algorithm implementation
	/// Time complexity:	O(N^2 / 2) in worst case(descending order)
	///						O(N-1) in best case(already in ascending order)
	/// Space complexity:	O(1)
	/// Best usage case:	sorting array is almost in ascending order and short array
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	class InsertSort : public SortBase<T> {
	public:
		InsertSort() {}
		~InsertSort() {};
		void sort(std::vector<T>& a) override;
	};
	template<typename T>
	void InsertSort<T>::sort(std::vector<T>& a) {
		for (int i = 1; i < a.size(); i++) {
			for (int j = i; j > 0 && SortBase<T>::less(a[j], a[j-1]); j--) {
				std::swap(a[j-1], a[j]);
			}
		}
	}

	/// <summary>
	/// Selection sort
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	class SelectSort : public SortBase<T> {
	public:
		SelectSort() {}
		~SelectSort() {};
		void sort(std::vector<T>& a) override;
	};
	template<typename T>
	void SelectSort<T>::sort(std::vector<T>& a) {
		for (size_t i = 0; i < a.size()-1; i++) {
			int min = i;
			for (size_t j = i+1; j < a.size();j++) {
				if (SortBase<T>::less(a[j], a[min])) {
					min = j;
				}
			}
			std::swap(a[i], a[min]);
		}
	}

}