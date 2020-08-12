#pragma once
#include "Graph.h"

namespace code047 {
	class TwoColor {
	private:
		Graph _G;
		bool _twoColorable;
		std::vector<bool> _marked;
		std::vector<bool> _color;
	private:
		void dfs(const Graph& G, int v);
	public:
		TwoColor(const Graph& G);
		TwoColor(const TwoColor& other);
		TwoColor& operator=(const TwoColor& other);
		~TwoColor() {}
	public:
		bool isBipartite();
	};
}