#pragma once
#include "Graph.h"

namespace code047 {
	class Paths {
	public:
		Paths(const Graph &G, int s) : _G(G), _s(s) {};
		Paths(const Paths& other) : _G(other._G), _s(other._s){}
		Paths& operator=(const Paths& other) {
			if (&other != this) {
				_G = other._G;
				_s = other._s;
			}
			return *this;
		}
		~Paths(){}

	public:
		virtual bool hasPathTo(int v) = 0;
		virtual std::vector<int> pathTo(int v) = 0;
	protected:
		Graph _G;
		int _s;
	};
}

