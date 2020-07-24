/*********************************************************************
Funtion :		LSD sort algorithm for fixed length of strings

Time complexity£ºO(WN+WR) ~ O(WN)
		
		   W represents fixed length of strings
		   R represents character set of strings
		   Both W and R consider as constants
		   So LSD algorithm is linear sort algorithm for fixed length string

Space complexity£ºO(R+N)~O(N)

		   aux array consumes O(N) space, and count array consumes O(R) space
		   O(R+N) ~ O(N) in total, so LSD algorithm is also linear in space complexity

Author:			  Code047

Date:			  2020/07/23
*********************************************************************/
#pragma once
#include <string>
#include <vector>

namespace code047 {
	class LSD
	{
	public:
		static void sort(std::vector<std::string>& strings, const int& w);
	};
}


