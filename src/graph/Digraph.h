#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include "../fileHelper/FileReader.h"

namespace code047 {
	class Digraph {
	public:
		Digraph(size_t V);
		Digraph(std::string file);
		~Digraph();
		Digraph(const Digraph&);
		Digraph& operator=(const Digraph&);
	public:
		int V() const { return _V; }
		int E() const { return _E; }
		void addEdge(const int v, const int w);
		std::vector<int> adj(const int v) const;
		Digraph reverse() const;
		std::string toString();
	private:
		int _V;
		int _E;
		std::vector<std::vector<int>> _adjList;
	};
}
