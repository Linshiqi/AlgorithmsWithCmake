#pragma once
#include "SubStringBase.h"
#include <vector>

namespace code047 {
	class Kmp : public SubStringBase {
	public:
		explicit Kmp(int R);
		~Kmp() {}
		Kmp(const Kmp& other);
		Kmp& operator=(const Kmp& other);
	public:
		size_t search(std::string& txt, std::string& pat) override;
	private:
		void build_dfa(std::string& pat);
	private:
		int _R;
		std::vector<std::vector<size_t>> _dfa;
	};
}