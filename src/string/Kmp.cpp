#include "Kmp.h"

namespace code047 {
	Kmp::Kmp(int R) : _R(R) {
		this->_dfa.resize(R);
	}

	Kmp::Kmp(const Kmp& other) : _R(other._R),_dfa(other._dfa) {
		
	}
	Kmp& Kmp::operator=(const Kmp& other) {
		if (this != &other) {
			this->_R = other._R;
			this->_dfa = other._dfa;
		}
		return *this;
	}

	void Kmp::build_dfa(std::string& pat) {
		if (pat.empty()) {
			return;
		}
		const size_t M = pat.length();
		for (auto v : this->_dfa) {
			v.resize(M, 0);
		}
		this->_dfa[0][0] = 1;	// ��ʼ����һ��״̬
		for (size_t X = 0, j = 1; j < M; j++) {
			for (int c = 0; c < this->_R; c++) {
				this->_dfa[c][j] = this->_dfa[c][X];	// ��ƥ�临��X֮ǰ��״̬
			}
			this->_dfa[pat[j]][j] = j+1;		// ƥ�������һ״̬
			X = this->_dfa[pat[j]][X];			// ����X״̬
		}
	}

	size_t Kmp::search(std::string& txt, std::string& pat) {
		// �������
		if (txt.empty() || pat.empty()) {
			return 0;	// �մ�����0
		}
		const size_t N = txt.length();
		const size_t M = pat.length();
		// ����״̬��
		build_dfa(pat);
		
		// ִ��KMP����
		size_t i, j;
		for (i = 0, j = 0; i < N && j < M; i++) {
			j = _dfa[txt[i]][j];
		}
		if (j == M) {	// �ҵ�
			return i - M;
		}
		return N;		// û�ҵ�
	}

}