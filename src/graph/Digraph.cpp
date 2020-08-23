#include "Digraph.h"
//
//namespace code047 {
//	Digraph::Digraph() {
//
//	}
//	Digraph::~Digraph() {}
//	Digraph::Digraph(const Digraph& other) : _V_count(other._V_count), _E_count(other._E_count){
//
//	}
//	Digraph& Digraph::operator=(const Digraph& other) {
//		if (this != &other) {
//			this->_V_count = other._V_count;
//			this->_E_count = other._E_count;
//		}
//		return *this;
//	}
//
//	void Digraph::addEdge(const int v, const int w) {
//		if (this->adjList.size() < v) {
//			this->adjList.resize(v);
//		}
//
//		this->adjList[v].push_back(w);	// add edge v->w
//		this->_V_count++;
//		this->_E_count++;
//	}
//	std::vector<int> Digraph::adj(const int v) const {
//		std::vector<int> res;
//		if (this->adjList.size() <= v) {
//			// out of range;
//			return res;
//		}
//		for (int w : this->adjList[v]) {
//			res.push_back(w);
//		}
//		return res;
//	}
//	std::string Digraph::toString() {
//		std::string s;/* = std::to_string(code047::Graph::getV()) + " vertices " + std::to_string(code047::Graph::getE()) + " edges\n";
//		for (int v = 0; v < getV(); v++) {
//			s += std::to_string(v) + " :";
//			for (int adj : adjList[v]) {
//				s += std::to_string(adj) + " ";
//			}
//			s += "\n";
//		}*/
//		return s;
//	}
//
//
//}