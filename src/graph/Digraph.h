#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include "Graph.h"
#include "../fileHelper/FileReader.h"

namespace code047 {
	class Digraph {
	public:
		Digraph();
		~Digraph();
		Digraph(const Digraph&);
		Digraph& operator=(const Digraph&);
	public:
		int V() const { return _V_count; }
		int E() const { return _E_count; }
		void addEdge(const int v, const int w);
		std::vector<int> adj(const int v) const;
		std::string toString();
	private:
		int _V_count;
		int _E_count;
		std::vector<std::vector<int>> adjList;
	};
}
