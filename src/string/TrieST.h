#pragma once
#include "StringST.h"

namespace code047 {
	template<typename T>
	class TrieST : public StringST<T> {
	public:
		void put(std::string& key, T& value) override;
		std::shared_ptr<T> get(std::string& key) override;
		int size() override;
		void deleteKey(std::string& key) override;
	private:
		std::shared_ptr<Node<T>> root;
		const int R = 256;
	public:
		TrieST() {}
		~TrieST() {}
		TrieST(const TrieST<T>& other) : root(other.root) {}
		TrieST<T>& operator=(const TrieST<T>& other) {
			if (this != other) {
				root = other.root;
			}
			return *this;
		}
	private:
		std::shared_ptr<Node<T>> put(std::shared_ptr<Node<T>> node_ptr, std::string& key, T value, int index);
	};
}