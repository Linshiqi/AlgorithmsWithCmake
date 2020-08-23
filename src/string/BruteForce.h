/*************************************************************************************
Function:	substring search implemented with brute force method

Date:		2020/08/21

Author:		code047

Properties:
	Time:	O(NM) N is txt.length M is pat.length
	Space:	O(1) in place 
**************************************************************************************/
#pragma once
#include "SubStringSearch.h"
namespace code047 {
	class BruteForce : public SubStringSearch {
	public:
		BruteForce() {}
		~BruteForce() {}
	public:
		BruteForce(const BruteForce&) = delete;
		BruteForce& operator=(const BruteForce&) = delete;
	public:
		size_t searchFirstOccurrence(std::string& txt, std::string& pat) override;
	/*	std::vector<size_t> searchAllOccurrence(std::string& txt, std::string& pat) override {
			std::vector<size_t> res; 
			return res;
		}*/
	};
}