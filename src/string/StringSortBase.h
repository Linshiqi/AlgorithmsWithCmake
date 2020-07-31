#pragma once
#include <vector>
#include <string>
namespace {
	class StringSortBase {
	public:
		StringSortBase() {}
		StringSortBase(const StringSortBase&) = delete;
		StringSortBase& operator=(const StringSortBase&) = delete;
		virtual ~StringSortBase() {};
		virtual void sort(std::vector<std::string>& a) = 0;
	protected:
		const int R = 256;		// Enough for ASCII characters
	};
}