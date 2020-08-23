#include "TwoColor.h"

namespace code047 {
	TwoColor::TwoColor(const Graph& G) : _G(G), _twoColorable(true) {
		_marked.resize(G.getV(), false);
		_color.resize(G.getV(), false);
		for (int i = 0; i < _G.getV(); i++) {
			if (!_marked[i]) {
				dfs(_G, i);
			}
		}
	}

	TwoColor::TwoColor(const TwoColor& other):
		_G(other._G), 
		_twoColorable(other._twoColorable),
		_marked(other._marked),
		_color(other._color)
	{
	}

	TwoColor& TwoColor::operator=(const TwoColor& other) {
		if (this != &other) {
			this->_G = other._G;
			this->_twoColorable = other._twoColorable;
			this->_marked = other._marked;
			this->_color = other._color;
		}
		return *this;
	}

	void TwoColor::dfs(const Graph& G, int v) {
		_marked[v] = true;
		for (int i : G.adj(v)) {
			if (!_marked[i]) {
				_color[i] = !_color[v];
				dfs(G, i);
			}
			else if (_color[i] == _color[v]) {
				_twoColorable = false;
			}
		}
	}

	bool TwoColor::isBipartite() {
		return _twoColorable;
	}

}