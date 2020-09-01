/***********************************************************************************
Function: 
	Given a directed graph, compute it's strongly connected components

Strongly Connected Components:
	In strongly connected components, any v and w vertex has a path to each other

How to compute strongly connected components:
	First, 
***********************************************************************************/
#pragma once
#include "Digraph.h"
#include "DGDFSOrder.h"
namespace code047 {
	class SCC {
	public:
		SCC(const Digraph& DG);
		~SCC() {}
		SCC(const SCC& other) = delete;
		SCC& operator=(const SCC& other) = delete;
	public:
		int count() { return _count; }	// return the number of strongly connected components
		int id(int v) { return _id[v]; };	//  return which strongly connected component v belong to
		bool stronglyConnected(int v, int w) { return _id[v] == _id[w]; };	// is v strongly connected with w
	private:
		void dfs(const Digraph& DG, int v);
	private:
		std::vector<int> _marked;
		std::vector<int> _id;
		int _count;
	};
}