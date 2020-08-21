#include "BruteForce.h"

namespace code047 {
	size_t BruteForce::searchFirstOccurrence(std::string& txt, std::string& pat) {
		const size_t N = txt.length();
		const size_t M = pat.length();

		size_t i = 0;
		size_t j = 0;
		for (; i < N && j < M; i++) {
			if (txt[i] == pat[j]) {
				j++;
				//i++  is in for loop
			}
			else {
				i = i - j;	// i++ is in for loop, after this for end i is i-j+1
				j = 0;
			}
		}
		if (j == M) {
			// found
			return i - M;
		}
		else {
			// not found
			return N;
		}
	}

	std::vector<size_t> BruteForce::searchAllOccurrence(std::string& txt, std::string& pat) {
		const size_t N = txt.length();
		const size_t M = pat.length();

		size_t i = 0;
		size_t j = 0;
		for (; i < N && j < M; i++) {
			if (txt[i] == pat[j]) {
				j++;
				//i++  is in for loop
			}
			else {
				i = i - j;	// i++ is in for loop, after this for end i is i-j+1
				j = 0;
			}
		}
		if (j == M) {
			// found
			return i - M;
		}
		else {
			// not found
			return N;
		}
	}
}