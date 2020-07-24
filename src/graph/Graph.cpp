#include "Graph.h"
#include "../fileHelper/FileReader.h"

namespace code047 {
	Graph::Graph(int V) : V(V), E(0), adjList(V){
		for (auto it = adjList.begin(); it != adjList.end(); it++) {
			*it = std::vector<int>(0);
		}
	}

	Graph::Graph(std::string file) : V(0), E(0), adjList(V) {
		std::vector<std::string> lines = FileReader::readLines(file);
		if (lines.size() <= 2) {
			std::cout << "file " << file << " is not  correct." << std::endl;
			abort();
		}
		V = std::stoi(lines[0]);
		adjList.resize(V);
		for (auto it = lines.begin() + 2; it != lines.end(); it++) {
			std::vector<int> vertexPair = FileReader::getVertexPair(*it);
			if (vertexPair.size() != 2) {
				std::cout << "file " << file << " is not correct." << std::endl;
				abort();
			}
			addEdge(vertexPair[0], vertexPair[1]);
		}
	}

	void Graph::addEdge(int v, int w) {
		if (!checkArgInRange(v) || !checkArgInRange(w)) {
			return;
		}
		adjList[v].push_back(w);
		adjList[w].push_back(v);
		E++;
	}

	std::vector<int> Graph::adj(int v) const {
		if (!checkArgInRange(v)) {
			return std::vector<int>();
		}
		return adjList[v];
	}

	std::string Graph::toString() {
		std::string s = std::to_string(getV()) + " vertices " + std::to_string(getE()) + " edges\n";
		for (int v = 0; v < getV(); v++) {
			s += std::to_string(v) + " :";
			for (int adj : adjList[v]) {
				s += std::to_string(adj) + " ";
			}
			s += "\n";
		}
		return s;
	}

	int Graph::degree(const Graph &G, int v) {
		if (!G.checkArgInRange(v)) {
			return -1;
		}
		return G.adjList[v].size();
	}

	int Graph::maxDegree(const Graph& G) {
		int max = -1;
		for (int i = 0; i < G.getV(); i++) {
			int iDegree = G.degree(G, i);
			if (iDegree > max) {
				max = iDegree;
			}
		}
		return max;
	}

	int Graph::avgDegree(const Graph& G) {
		int totalDegree = G.getE() * 2;
		return totalDegree / G.getV();
	}

	int Graph::numberOfSelfLoops(const Graph& G) {
		int count = 0;
		for (int v = 0; v < G.getV(); v++) {
			for (int adjV : G.adj(v)) {
				if (adjV == v) {
					count++;
				}
			}
		}

		return count / 2;
	}
}