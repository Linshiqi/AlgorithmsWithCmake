#pragma once
#include "Digraph.h"

namespace code047 {
	class DirectedDFS {
	public:
		DirectedDFS() = delete;
		~DirectedDFS() = default;
		DirectedDFS(const DirectedDFS&) = delete;
		DirectedDFS& operator=(const DirectedDFS&) = delete;
	public:
		DirectedDFS(const Digraph& G, int s);
		DirectedDFS(const Digraph& G, std::vector<int> sources);
	public:
		bool marked(int v) { return _marked[v]; }
	private:
		void dfs();
	private:
		std::vector<bool> _marked;
	};
}