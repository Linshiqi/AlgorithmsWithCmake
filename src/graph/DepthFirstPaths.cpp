#include "DepthFirstPaths.h"
namespace code047 {
	bool DepthFirstPaths::hasPathTo(int v) {
		if (v >= 0 && v < this->_G.getV()) {
			return marked[v];
		}
		else {
			throw std::out_of_range(v+" out of range");
		}
	}

	std::vector<int> DepthFirstPaths::pathTo(int v) {
		std::vector<int> res;

		if (!hasPathTo(v)) {
			return res;
		}
		for (int i = v; i != this->_s;i = edgeTo[i]) {

			res.push_back(i);
		}
		res.push_back(this->_s);
		std::reverse(res.begin(), res.end());

		return res;
	}

	void DepthFirstPaths::dfs(const Graph &G, int v) {
		marked[v] = true;
		for (int i : G.adj(v)) {
			if (!marked[i]) {
				edgeTo[i] = v;
				dfs(G, i);
			}
		}
	}
}