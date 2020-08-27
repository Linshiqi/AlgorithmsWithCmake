#include "DAGTopoSort.h"

namespace code047 {
	DAGTopoSort::DAGTopoSort(const Digraph& DG) : _DG(DG),  _topoOrder() {}
	
	bool DAGTopoSort::isDAG() {
		DirectedCycle dc(_DG);
		return !dc.hasCycle();
	}

	std::vector<int>& DAGTopoSort::topoOrder() {
		if (this->isDAG()) {
			DGDFSOrder ds(_DG);
			_topoOrder = ds.getReversePostOrder();
		}

		return _topoOrder;
	}

}