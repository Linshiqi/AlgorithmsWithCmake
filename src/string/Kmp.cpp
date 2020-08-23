#include "Kmp.h"

namespace code047 {
	Kmp::Kmp(const int R) : _R(R) {
		this->_dfa.resize(R);
	}
	Kmp::Kmp(const Kmp& other) : _R(other._R),_dfa(other._dfa) {
		
	}

	Kmp& Kmp::operator=(const Kmp& other) {
		if (&other != this) {
			this->_R = other._R;
			this->_dfa = other._dfa;
		}
		return *this;
	}

	void Kmp::build_dfa(const int states, std::string& pat) {
		this->_dfa[pat[0]][0] = 1;
		for (int X = 0, j = 1; j < states; j++) {
			for (int r = 0; r < this->_R; r++) {
				this->_dfa[r][j] = this->_dfa[r][X];	// Copy mismatch
			}
			this->_dfa[pat[j]][j] = j + 1;				// Set match case
			X = this->_dfa[pat[j]][X];					// Update X
		}
	}

	int Kmp::search(std::string& txt, std::string& pat) {
		const int states = pat.length();

		// Check input
		if (this->_dfa.size() == 0 || states == 0) {
			return txt.length();
		}

		// Initialize
		for (auto v : this->_dfa) {
			v.resize(states, 0);
		}

		// build dfa
		build_dfa(states, pat);
		
		// Use Kmp for substring search
		int i, j;
		for (i = 0, j = 0; i < txt.length() && j < states; i++) {
			j = this->_dfa[txt[i]][j];
		}
		if (j == states) {
			return i - states;
		}
		return txt.length();
	}

	

}