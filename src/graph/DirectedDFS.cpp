#include "DirectedDFS.h"
namespace code047 {
	DirectedDFS::DirectedDFS(const Digraph& G, int s){
		this->_marked.resize(G.V(), false);
	}

	DirectedDFS(const Digraph& G, std::vector<int> sources) : _G(G), _sources(sources) {
		this->_marked.resize(G.V(), false);
	}

	
}