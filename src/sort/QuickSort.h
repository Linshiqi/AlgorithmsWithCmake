#pragma once
#include <exception>
#include <stdlib.h>
#include <algorithm>
#include "SortBase.h"

namespace code047 {
	template<typename T>
	class QuickSort : public SortBase<T> {
	public:
		QuickSort() {}
		~QuickSort() {}
	public:
		void sort(std::vector<int>& a) override {
			shuffle(a);
			quicksort(a, 0, a.size() - 1);
		}
	private:
		void quicksort(std::vector<int>& a, size_t low, size_t hi);
		size_t partition(std::vector<int>& a, size_t low, size_t hi);
		void shuffle(std::vector<int>& a);
	};

	template<typename T>
	void QuickSort<T>::quicksort(std::vector<int>& a, size_t low, size_t hi) {
		if (hi > a.size() - 1) {
			throw new std::out_of_range("invalid input");
		}
		if (low >= hi) return;
		size_t index = partition(a, low, hi);
		if (index != 0) {
			quicksort(a, low, index - 1);
		}
		quicksort(a, index + 1, hi);
	}

	template<typename T>
	size_t QuickSort<T>::partition(std::vector<int>& a, size_t lo, size_t hi) {
		int e = a[lo];
		size_t i = lo;
		size_t j = hi + 1;
		while (true) {
			while (a[++i] < e) if (i == hi) break;
			while (a[--j] > e) if (j == lo) break;
			if (i >= j) break;
			std::swap(a[i], a[j]);
		}
		std::swap(a[lo], a[j]);
		return j;
	}

	template<typename T>
	void QuickSort<T>::shuffle(std::vector<int>& a) {
		const size_t N = a.size();
		for (size_t i = 0; i < N; i++) {
			size_t j = static_cast<size_t>(rand() % (N-i));
			std::swap(a[i], a[j]);
		}
	}
}
