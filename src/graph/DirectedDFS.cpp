#include "DirectedDFS.h"
namespace code047 {
	DirectedDFS::DirectedDFS(const Digraph& G, int s) : _marked(G.V(), false){
		dfs(G, s);
	}

	DirectedDFS::DirectedDFS(const Digraph& G, std::vector<int>& sources) : _marked(G.V(), false) {
		for (auto i : sources) {
			if (!_marked[i]) {
				dfs(G, i);
			}
		}
	}

	void DirectedDFS::dfs(const Digraph& DG, int v) {
		_marked[v] = true;
		for (auto i : DG.adj(v)) {
			if (!_marked[i]) {
				dfs(DG, i);
			}
		}
	}

}