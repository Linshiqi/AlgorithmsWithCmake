#pragma once
#include <vector>
#include "GraphSearch.h"

namespace code047 {
	class DepthFirstSearch : public GraphSearch {
	public:
		DepthFirstSearch(Graph G, int s) : GraphSearch(G, s) {
			visited.resize(G.getV(), false);
			_count = 0;
			dfs(G, s);
		}
		~DepthFirstSearch() {}
		bool marked(int v) override;
		int count() override;
	private:
		void dfs(Graph G, int s);
		std::vector<bool> visited;
		int _count;
	};
}
