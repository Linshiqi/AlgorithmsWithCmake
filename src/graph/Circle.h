#pragma once
#include "Graph.h"

namespace code047 {
	class Circle {
	private:
		Graph _G;
		std::vector<bool> _marked;
		bool _hasCircle;
	public:
		bool hasCircle() {
			return _hasCircle;
		}
	private:
		/// <summary>
		/// Detect circle 
		/// </summary>
		/// <param name="G"></param>
		/// <param name="v"></param>
		/// <param name="u"></param>
		void dfs(const Graph& G, int v, int u);
	public:
		Circle(const Graph& G);
		Circle(const Circle& other);
		Circle& operator=(const Circle& other);
		~Circle() {}
	};
}