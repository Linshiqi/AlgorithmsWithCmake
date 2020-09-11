#pragma once

#include "SortBase.h"

namespace code047 {
	template<typename T>
	class MergeSort : public SortBase<T>{
	public:
		MergeSort() {}
		~MergeSort() {}
		void sort(std::vector<T>& a) override;
	private:
		void merge(std::vector<T>& a, size_t low, size_t mid, size_t hi);
		void sort(std::vector<T>& a, size_t low, size_t hi);
	};

	template<typename T>
	void MergeSort<T>::merge(std::vector<T>& a, size_t low, size_t mid, size_t hi) {
		bool inputValid = (low >= 0 && mid >= low && mid <= hi && hi <= a.size() - 1);
		if (!inputValid) return;
		// merge a[low, mid] and a[mid+1, hi]
		std::vector<T> tmp(a);
		size_t k = low;
		size_t m = mid + 1;
		for (size_t i = low; i <= hi; i++) {
			if (k > mid) {
				// left is empty, copy right
				a[i] = tmp[m++];
			}
			else if (m > hi) {
				// right is empty, copy left
				a[i] = tmp[k++];
			}
			else {
				// select smaller value from both site
				a[i] = SortBase<T>::less(tmp[k], tmp[m]) ? tmp[k++] : tmp[m++];
			}
		}
	}

	template<typename T>
	void MergeSort<T>::sort(std::vector<T>& a, size_t low, size_t hi) {
		if (low >= hi) {
			// 小于等于1个元素已经有序
			return;
		}
		size_t mid = low + ((hi - low) >> 1);
		sort(a, low, mid);			// sort left
		sort(a, mid + 1, hi);		// sort right
		merge(a, low, mid, hi);		// merger both
	}

	template<typename T>
	void MergeSort<T>::sort(std::vector<T>& a) {
		size_t N = a.size() - 1;
		sort(a, 0, N);	
	}
}