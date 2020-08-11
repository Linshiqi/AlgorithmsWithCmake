#pragma once
#include "Graph.h" 

namespace code047
{
	class CC {
	private:
		Graph _G;
		std::vector<int> _marked;
		std::vector<int> _id;
		int _count;
	private:
		void dfs(const Graph &G, int v);
	public:
		CC(const Graph& G) : _G(G) {
			_marked.resize(G.getV(), false);
			_id.resize(G.getV(), 0);
			_count = 0;

			for (int i = 0; i < _G.getV(); i++) {
				if (!_marked[i]) {
					dfs(_G, i);
					_count++;
				}
			}
		}
		CC(const CC& other) : 
			_G(other._G), _marked(other._marked), _id(other._id), _count(other._count) {}
		CC& operator=(const CC& other) {
			if (this != &other) {
				_G = other._G;
				_marked = other._marked;
				_id = other._id;
				_count = other._count;
			}
			return *this;
		}
	public:
		bool connected(int v, int w) {
			return _id[v] == _id[w];
		}
		int count() {
			return _count;
		}
		int id(int v) {
			return _id[v];
		}
	};
}