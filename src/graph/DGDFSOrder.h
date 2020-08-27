#pragma once
#include <vector>
#include <algorithm>
/*****************************************************************************************
Function:	Compute pre¡¢post¡¢reverse order of a dag
******************************************************************************************/
#include "Digraph.h"

namespace code047 {
	class DGDFSOrder {
	public:
		DGDFSOrder(const Digraph& DG);
		~DGDFSOrder() {};
	public:
		DGDFSOrder() = delete;
		DGDFSOrder(const DGDFSOrder&) = delete;
		DGDFSOrder& operator=(const DGDFSOrder&) = delete;
	public:
		std::vector<int>& getPreOrder() {
			return _preOrder;
		}
		std::vector<int>& getPostOrder() {
			return _postOrder;
		}
		std::vector<int>& getReversePostOrder() {
			std::reverse(_reversePostOrder.begin(), _reversePostOrder.end());
			return _reversePostOrder;
		}
	private:
		void dfs(const Digraph& DG, int v);
	private:
		std::vector<int> _marked;
		std::vector<int> _preOrder;
		std::vector<int> _postOrder;
		std::vector<int> _reversePostOrder;
	};
}