#include "CC.h"

namespace code047 {
	void CC::dfs(const Graph &G, int v) {
		if (v >= 0 && v < G.getV()) {
			_marked[v] = true;
			_id[v] = _count;
			for (int i : G.adj(v)) {
				if (!_marked[i]) {
					dfs(G, i);
				}
			}
		}
		else {
			throw std::out_of_range(v + " out of range");
		}
	}
}