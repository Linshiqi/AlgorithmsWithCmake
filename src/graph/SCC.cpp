#include "SCC.h"

namespace code047 {
	SCC::SCC(const Digraph& DG) : _marked(DG.V(), false), _id(DG.V(), -1), _count(0) {
		Digraph tmp = DG.reverse();
		DGDFSOrder dfsOrder(tmp);
		std::vector<int> reverseOrder = dfsOrder.getReversePostOrder();
		for (int v: reverseOrder) {
			if (!_marked[v]) {
				dfs(DG, v);
				_count++;
			}
		}
	}

	void SCC::dfs(const Digraph& DG, int v) {
		_marked[v] = true;
		_id[v] = _count;
		for (auto e : DG.adj(v)) {
			if (!_marked[e]) {
				dfs(DG, e);
			}
		}
	}
}