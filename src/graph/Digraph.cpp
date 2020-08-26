#include "Digraph.h"

namespace code047 {
	Digraph::Digraph(size_t V) : _V(V), _E(0),_adjList(V) {

	}
	Digraph::~Digraph() {}
	Digraph::Digraph(const Digraph& other) : _V(other._V), _E(other._E){

	}
	Digraph& Digraph::operator=(const Digraph& other) {
		if (this != &other) {
			this->_V = other._V;
			this->_E = other._E;
		}
		return *this;
	}

	void Digraph::addEdge(const int v, const int w) {
		if (this->_adjList.size() < v) {
			this->_adjList.resize(v);
		}

		this->_adjList[v].push_back(w);	// add edge v->w
		this->_E++;
	}
	Digraph::Digraph(std::string file) : _V(0), _E(0), _adjList(0) {
		std::vector<std::string> lines = FileReader::readLines(file);
		if (lines.size() <= 2) {
			std::cout << "file " << file << " is not  correct." << std::endl;
			abort();
		}
		_V = std::stoi(lines[0]);
		_adjList.resize(_V);
		for (auto it = lines.begin() + 2; it != lines.end(); it++) {
			std::vector<int> vertexPair = FileReader::getVertexPair(*it);
			if (vertexPair.size() != 2) {
				std::cout << "file " << file << " is not correct." << std::endl;
				abort();
			}
			addEdge(vertexPair[0], vertexPair[1]);
		}
	}
	std::vector<int> Digraph::adj(const int v) const {
		std::vector<int> res;
		if (this->_adjList.size() <= v) {
			// out of range;
			return res;
		}
		for (int w : this->_adjList[v]) {
			res.push_back(w);
		}
		return res;
	}
	std::string Digraph::toString() {
		std::string s = _V + " vertices " + std::to_string(_E) + " edges\n";
		for (int v = 0; v < _V; v++) {
			s += std::to_string(v) + " :";
			for (int adj : _adjList[v]) {
				s += std::to_string(adj) + " ";
			}
			s += "\n";
		}
		return s;
	}
}