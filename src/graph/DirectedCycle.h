#pragma once
#include <vector>
#include "Digraph.h"

namespace code047 {
	class DirectedCycle {
	public:
		DirectedCycle(const Digraph& DG);
		~DirectedCycle() {}
	public:
		DirectedCycle() = delete;
		DirectedCycle(const DirectedCycle&) = delete;
		DirectedCycle& operator=(const DirectedCycle&) = delete;
	public:
		bool hasCycle() { return _hasCycle; }
		std::vector<int>& getCycleVectices() { return _cycleVertices; }
	private:
		void detectCycleByDfs(const Digraph& DG, const int s);
	private:
		bool _hasCycle;
		std::vector<int> _cycleVertices;
		std::vector<bool> _marked;
		std::vector<int> _edgeTo;
		std::vector<bool> _onStack;
	};
}
