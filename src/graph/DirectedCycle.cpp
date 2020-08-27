#include "DirectedCycle.h"

namespace code047 {
	DirectedCycle::DirectedCycle(const Digraph& DG) 
		: _hasCycle(false), 
		_cycleVertices(0), 
		_marked(DG.V(), false),
		_edgeTo(DG.V()),
		_onStack(DG.V(), false)
	{
		for (int i = 0; i < DG.V(); i++) {
			if (!_marked[i]) {
				detectCycleByDfs(DG, i);
			}
		}
	}

	void DirectedCycle::detectCycleByDfs(const Digraph& DG, const int s) {
		_onStack[s] = true;				// for every new dfs search
		_marked[s] = true;
		for (auto i : DG.adj(s)) {
			if (_hasCycle) return;		// very important here

			_edgeTo[i] = s;
			if (!_marked[i]) {
				detectCycleByDfs(DG, i);
			}
			else if(_onStack[i]){	// detect a cycle
				_hasCycle = true;
				_cycleVertices.push_back(i);
				for (int x = s; x != i; x = _edgeTo[x]) {
					_cycleVertices.push_back(x);
				}
				_cycleVertices.push_back(i);
				break;
			}
		}
		_onStack[s] = false;
	}


}