#pragma once

#include "SubStringBase.h"

namespace code047 {
	class Kmp : public SubStringBase {
	public:
		Kmp() {}
		~Kmp() {}
		Kmp(const Kmp& other);
		Kmp& operator=(const Kmp& other);
	public:
		int search(std::string& txt, std::string& pat) override;
	};
}