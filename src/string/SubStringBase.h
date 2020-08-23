#pragma once
#include <string>

namespace code047 {
	class SubStringBase {
	public:
		SubStringBase() {}
		virtual ~SubStringBase() {}
		SubStringBase(const SubStringBase&) = delete;
		SubStringBase& operator=(const SubStringBase&) = delete;
	public:
		virtual int search(std::string& txt, std::string& pat) = 0;
	};
}