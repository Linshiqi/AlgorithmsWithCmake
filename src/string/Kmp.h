#pragma once

#include "SubStringBase.h"

namespace code047 {
	class Kmp : public SubStringBase {
	public:
		Kmp(const int R);
		~Kmp() {};
		Kmp(const Kmp& other);
		Kmp& operator=(const Kmp& other);
	public:
		int search(std::string& txt, std::string& pat) override;
	private:
		void build_dfa(const int states, std::string& pat);
	private:
		int _R;
		std::vector<std::vector<int>> _dfa;
	};
}