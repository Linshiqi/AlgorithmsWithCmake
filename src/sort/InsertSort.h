#pragma once

#include "SortBase.h"

namespace code047 {
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
			for (int j = i; j > 0 && less(a[j], a[j-1]); j--) {
				std::swap(a[j-1], a[j]);
			}
		}
	}
}