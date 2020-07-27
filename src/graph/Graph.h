#pragma once
#include <string>
#include <vector>
#include <iostream>
namespace code047{
	class Graph {
	public:
		Graph() :  V(0), E(0), adjList(V) {
			
		}

		Graph(const Graph& g) : V(g.V), E(g.E), adjList(g.adjList){
			
		}

		Graph& operator=(const Graph& g) {
			// Graph Don't have heap memory, so don't need care self copy assignment
			V = g.V;
			E = g.E;
			adjList = g.adjList;
			return *this;
		}

		~Graph() {

		}

		/// <summary>
		/// Create a V-vertex graph with no edges
		/// </summary>
		/// <param name="V">number of vertices</param>
		/// <returns></returns>
		Graph(int V);

		/// <summary>
		/// Read a graph from a file
		/// </summary>
		/// <param name="file">file name with path</param>
		/// <returns></returns>
		Graph(std::string file);

		/// <summary>
		/// Number of vertices
		/// </summary>
		/// <returns></returns>
		int getV() const {
			return V;
		}

		/// <summary>
		/// Number of edeges
		/// </summary>
		/// <returns></returns>
		int getE() const {
			return E;
		}

		/// <summary>
		/// Add edge v-w to this graph
		/// </summary>
		/// <param name="v"></param>
		/// <param name="w"></param>
		void addEdge(int v, int w);

		/// <summary>
		/// Vertices adjacent to v
		/// </summary>
		/// <param name="v"></param>
		/// <returns></returns>
		std::vector<int> adj(int v) const;

		/// <summary>
		/// String representation
		/// </summary>
		/// <returns></returns>
		std::string toString();

		/// <summary>
		/// Compute the degree of v
		/// </summary>
		/// <param name="G"></param>
		/// <param name="v"></param>
		/// <returns></returns>
		static int degree(const Graph& G, int v);

		/// <summary>
		/// Compute maximum degree
		/// </summary>
		/// <param name="G"></param>
		/// <returns></returns>
		static int maxDegree(const Graph& G);

		/// <summary>
		/// Compute average degree
		/// </summary>
		/// <param name="G"></param>
		/// <returns></returns>
		static int avgDegree(const Graph& G);

		/// <summary>
		/// Compute self-loops
		/// </summary>
		/// <param name="G"></param>
		/// <returns></returns>
		static int numberOfSelfLoops(const Graph& G);
	private:
		/// <summary>
		/// Check arg in range [0, adjList.size()-1]
		/// </summary>
		/// <param name="arg"></param>
		/// <returns></returns>
		bool checkArgInRange(size_t arg) const {
			if (arg >= 0 && arg < adjList.size()) {
				return true;
			}
			else {
				std::cout << "arg out of range : " << arg << std::endl;
				return false;
			}
		}
		
		/// <summary>
		/// Number of Vetices
		/// </summary>
		int V;

		/// <summary>
		/// Number of edges
		/// </summary>
		int E;

		/// <summary>
		/// Adjacency list
		/// </summary>
		std::vector<std::vector<int>> adjList;
	};
}

