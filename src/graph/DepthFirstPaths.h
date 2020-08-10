#pragma once
#include <exception>
#include <algorithm>
#include "Paths.h"
namespace code047 {
	class DepthFirstPaths : public Paths {
	public:
		DepthFirstPaths(const Graph& G, int s) : Paths(G, s) {
			marked.resize(G.getV(), false);
			edgeTo.resize(G.getV(), 0);
			dfs(G, s);
		}
		DepthFirstPaths(const DepthFirstPaths& other) : Paths(other._G, other._s) {}
		DepthFirstPaths& operator=(const DepthFirstPaths& other) {
			if (this != &other) {
				this->_G = other._G;
				this->_s = other._s;
			}
			return *this;
		}
		~DepthFirstPaths() {}
	public:
		bool hasPathTo(int v) override;
		std::vector<int> pathTo(int v) override;
	private:
		/// <summary>
		/// Init marked and edgeTo
		/// </summary>
		void dfs(const Graph &G, int v);
	private:
		std::vector<int> marked;
		std::vector<int> edgeTo;
	};
}