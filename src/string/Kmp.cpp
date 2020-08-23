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
		this->_dfa[0][0] = 1;	// 初始化第一个状态
		for (size_t X = 0, j = 1; j < M; j++) {
			for (int c = 0; c < this->_R; c++) {
				this->_dfa[c][j] = this->_dfa[c][X];	// 不匹配复制X之前的状态
			}
			this->_dfa[pat[j]][j] = j+1;		// 匹配进入下一状态
			X = this->_dfa[pat[j]][X];			// 更新X状态
		}
	}

	size_t Kmp::search(std::string& txt, std::string& pat) {
		// 检查输入
		if (txt.empty() || pat.empty()) {
			return 0;	// 空串返回0
		}
		const size_t N = txt.length();
		const size_t M = pat.length();
		// 创建状态机
		build_dfa(pat);
		
		// 执行KMP查找
		size_t i, j;
		for (i = 0, j = 0; i < N && j < M; i++) {
			j = _dfa[txt[i]][j];
		}
		if (j == M) {	// 找到
			return i - M;
		}
		return N;		// 没找到
	}

}