#include "DepthFirstSearch.h"

namespace code047 {
	bool DepthFirstSearch::marked(int v) {
		return visited[v];
	}
	int DepthFirstSearch::count() {
		return _count;
	}
	void DepthFirstSearch::dfs(Graph G, int s) {
		visited[s] = true;
		_count++;
		for (auto v : G.adj(s)) {
			if (!marked(v)) {
				dfs(G, v);
			}
		}				
	}
}