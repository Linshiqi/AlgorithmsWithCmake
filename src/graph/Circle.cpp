#include "Circle.h"

namespace code047 {
	Circle::Circle(const Graph& G) : _G(G) {
		_marked.resize(G.getV());
		_hasCircle = false;

		for (int i = 0; i < _G.getV(); i++) {
			if (!_marked[i]) {
				dfs(_G, i, i);
			}
		}
	}
	Circle::Circle(const Circle& other) : 
		_G(other._G), 
		_marked(other._marked),
		_hasCircle(other._hasCircle) 
	{
	}
	Circle& Circle::operator=(const Circle& other) {
		if (this != &other) {
			_G = other._G;
			_marked = other._marked;
			_hasCircle = other._hasCircle;
		}
		return *this;
	}

	/// <summary>
	/// has a circle if G has a back path, and the back
	/// path is not point to it's parent 
	/// </summary>
	/// <param name="G"></param>
	/// <param name="v"></param>
	/// <param name="u"></param>
	void Circle::dfs(const Graph& G, int v, int u) {
		_marked[v] = true;
		for (int i : G.adj(v)) {
			if (!_marked[i]) {
				dfs(G, i, v);
			}
			else if (i != u) {
				_hasCircle = true;
			}
		}
	}

	
}