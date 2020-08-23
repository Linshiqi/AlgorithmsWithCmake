#include "SymbolGraph.h"

namespace code047 {
	SymbolGraph::SymbolGraph(std::string pathToFile, std::string delim) {
		std::vector<std::string> lines = FileReader::readLines(pathToFile);

		// Fist pass builds the index
		for (auto line : lines) {
			std::vector<std::string> vertices = split(line, delim);
			for (auto v : vertices) {
				if (_map.find(v) == _map.end()) {
					_map[v] = _map.size();
				}
			}
		}
		
		this->_G_ptr = std::make_shared<Graph>(_map.size());
		this->_keys.resize(_map.size());

		// Second pass build graph
		for (auto line : lines) {
			std::vector<std::string> vertices = split(line, delim);
			int v = _map[*(vertices.begin())];
			_keys[v] = *(vertices.begin());
			for (auto it = vertices.begin() + 1; it != vertices.end(); it++) {
				_keys[_map[*it]] = *it;
				this->G().addEdge(v, _map[*it]);
			}
		}
		
	}
	SymbolGraph::SymbolGraph(const SymbolGraph& other) :
		_G_ptr(other._G_ptr),
		_map(other._map),
		_keys(other._keys)
	{}

	SymbolGraph& SymbolGraph::operator=(const SymbolGraph& other) {
		if (this != &other) {
			this->_G_ptr = other._G_ptr;
			this->_map = other._map;
			this->_keys = other._keys;
		}
		return *this;
	}

	int SymbolGraph::index(const std::string& name) {
		if (_map.find(name) != _map.end()) {
			return _map[name];
		}
		else {
			return -1;
		}
	}
	std::string SymbolGraph::name(int v) {
		if (v >= 0 && v < _keys.size()) {
			return _keys[v];
		}
		else {
			return "";
		}
	}
	Graph& SymbolGraph::G() {
		return *(this->_G_ptr);
	}
}