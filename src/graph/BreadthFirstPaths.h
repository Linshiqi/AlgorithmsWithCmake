#pragma once
#include "Paths.h"
#include <queue>

namespace code047 {
	class BreadthFirstPaths : public Paths{
	private:
		std::vector<int> marked;
		std::vector<int> edgeTo;
	private:
		void bfs();
	public:
		bool hasPathTo(int v) override;
		std::vector<int> pathTo(int v) override;
	public:
		BreadthFirstPaths(const Graph& G, int s) : Paths(G, s) {
			marked.resize(G.getV(), false);
			edgeTo.resize(G.getV(), 0);
			bfs();
		}
		BreadthFirstPaths(const BreadthFirstPaths& other) : Paths(other._G, other._s) {}
		BreadthFirstPaths& operator=(const BreadthFirstPaths& other) {
			if (this != &other) {
				this->_G = other._G;
				this->_s = other._s;
			}
			return *this;
		}
		~BreadthFirstPaths() {}
	};
}