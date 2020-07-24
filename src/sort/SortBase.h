/*****************************************************************
Function:	This is Base class for all sort algorithm implementations

Author:		Code047

Date:		2020/07/24
******************************************************************/
#pragma once
#include <vector>
#include <functional>

namespace code047 {
	template<typename T, typename Compare = std::less<>>
	class SortBase {
	public:
		SortBase() {}
		virtual ~SortBase() {}

		virtual void sort(std::vector<T>& a) = 0;

		static bool less(T a, T b, Compare compare = Compare()) {
			return compare(a, b);
		}

		static bool isSorted(const std::vector<T>& a) {
			for (auto it = a.begin(); it != a.end() - 1; it++) {
				if (less(*(it + 1), *it)) {
					return false;
				}
			}
			return true;
		}
	};
}