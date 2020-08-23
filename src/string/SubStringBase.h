#pragma once
#include <string>
#include <vector>

namespace code047 {
	class SubStringBase {
	public:
		SubStringBase() {}
		virtual ~SubStringBase() {}
		SubStringBase(const SubStringBase&) = delete;
		SubStringBase& operator=(const SubStringBase&) = delete;
	public:
		virtual size_t search(std::string& txt, std::string& pat) = 0;
	};
}