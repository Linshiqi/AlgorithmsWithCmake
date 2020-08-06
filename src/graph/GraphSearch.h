#pragma once
#include "Graph.h"
namespace code047 {
	class GraphSearch {
	public:
		/// <summary>
		/// Find vertices connected to source vertex s
		/// </summary>
		/// <param name="G"></param>
		/// <param name="s"></param>
		/// <returns></returns>
		GraphSearch(Graph G, int s) : G(G), s(s) {};

		virtual ~GraphSearch() = default;

		/// <summary>
		/// If v connected to s
		/// </summary>
		virtual bool marked(int v) = 0;

		/// <summary>
		/// How many vertices connnected to s
		/// </summary>
		/// <returns></returns>
		virtual int count() = 0;
	protected:
		Graph G;
		int s;
	};
}