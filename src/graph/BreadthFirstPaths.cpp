#include "BreadthFirstPaths.h"

namespace code047 {
	bool BreadthFirstPaths::hasPathTo(int v) {
		if (v >= 0 && v < this->_G.getV()) {
			return marked[v];
		}
		else {
			throw std::out_of_range(v + " out of range");
		}
	}

	std::vector<int> BreadthFirstPaths::pathTo(int v) {
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

	void BreadthFirstPaths::bfs() {
		std::queue<int> vertices;
		marked[this->_s] = true;			// mark current vertex
		vertices.push(this->_s);
		while (!vertices.empty()) {
			int v = vertices.front();
			vertices.pop();
			for (int i : this->_G.adj(v)) {
				if (!marked[i]) {
					edgeTo[i] = v;
					marked[i] = true;
					vertices.push(i);
				}
			}
		}
	}

}