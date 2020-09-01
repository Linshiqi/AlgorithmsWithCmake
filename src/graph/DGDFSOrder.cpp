#include "DGDFSOrder.h"

namespace code047 {
	DGDFSOrder::DGDFSOrder(const Digraph& DG) 
		: _marked(DG.V(), false), _preOrder(0), _postOrder(0), _reversePostOrder(0)
	{
		for (int v = 0; v < DG.V(); v++) {
			if (!_marked[v]) {
				dfs(DG, v);
			}
		}
	}

	void DGDFSOrder::dfs(const Digraph& DG, int v) {
		_marked[v] = true;
		_preOrder.push_back(v);
		for (auto& w : DG.adj(v)) {
			if (!_marked[w]) {
				dfs(DG, w);
			}
		}
		_postOrder.push_back(v);
		_reversePostOrder.push_back(v);
	}
}