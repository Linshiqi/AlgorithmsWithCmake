/*****************************************************************************************
Function:	Compute dag topological sort

Date:		2020/08/27

Author:		code047

Proposition F:
	Reverse postorder in a DAG is a topological sort
	Proof: 
		Consider any edge v->w. One of the following three cases must hold when
		dfs(v) is called (see the diagram on page 583):
			¡ö dfs(w) has already been called and has returned (w is marked).
			¡ö dfs(w) has not yet been called (w is unmarked), so v->w will cause dfs(w) to
			be called (and return), either directly or indirectly, before dfs(v) returns.
			¡ö dfs(w) has been called and has not yet returned when dfs(v) is called. The
			key to the proof is that this case is impossible in a DAG, because the recursive
			call chain implies a path from w to v and v->w would complete a directed cycle.
		In the two possible cases, dfs(w) is done before dfs(v), so w appears before v in
		postorder and after v in reverse postorder. Thus, each edge v->w points from a vertex
		earlier in the order to a vertex later in the order, as desired.

Proposition G:
	With DFS, we can topologically sort a DAG in time proportional to O(V+E).
	Proof: 
		Immediate from the code. It uses one depth-first search to ensure that the graph has
		no directed cycles, and another to do the reverse postorder ordering. Both involve examining
		all the edges and all the vertices, and thus take time proportional to O(V+E).
*******************************************************************************************/
#include "DGDFSOrder.h"
#include "DirectedCycle.h"
namespace code047 {
	class DAGTopoSort {
	public:
		DAGTopoSort() = delete;
		DAGTopoSort(const DAGTopoSort&) = delete;
		DAGTopoSort& operator=(const DAGTopoSort&) = delete;
	public:
		DAGTopoSort(const Digraph&);
		~DAGTopoSort() {}
	public:
		bool isDAG();
		std::vector<int>& topoOrder();
	private:
		Digraph _DG;
		std::vector<int> _topoOrder;
	};
}
