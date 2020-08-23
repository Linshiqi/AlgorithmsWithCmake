#pragma once
#include "Graph.h"
#include "../utils/util.h"
#include <unordered_map>
#include <memory>
namespace code047 {
	class SymbolGraph {
	public:
		SymbolGraph(std::string pathToFile, std::string delim);
		SymbolGraph(const SymbolGraph& other);
		SymbolGraph& operator=(const SymbolGraph& other);

	public:
		int index(const std::string& name);
		std::string name(int v);
		Graph& G();
	private:
		std::shared_ptr<Graph> _G_ptr;
		std::unordered_map<std::string, int> _map;		// string to index
		std::vector<std::string> _keys;					// index to string
	};
}
