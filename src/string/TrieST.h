#pragma once
#include "StringST.h"

namespace code047 {
	template<typename T>
	class TrieST : public StringST<T> {
	public:
		void put(std::string& key, T& value) override;
		std::shared_ptr<T> get(std::string& key) override;
		int size() override {
			return total;
		}
		void deleteKey(std::string& key) override;
	public:
		std::string longestKeyPrefixOf(std::string& s) override { return ""; }
		std::vector<std::string > keysWithPrefix(std::string& s) override { return {}; }
		std::vector<std::string> keysThatMath(std::string& s) override { return {}; }

		std::vector<std::string> keys() { return {}; }
	private:
		std::shared_ptr<Node<T>> root;
		const int R = 256;
		int total;
	public:
		TrieST() : total(0){}
		~TrieST() {}
		TrieST(const TrieST<T>& other) : root(other.root), total(other.total) {}
		TrieST<T>& operator=(const TrieST<T>& other) {
			if (this != other) {
				root = other.root;
				total = other.total;
			}
			return *this;
		}
	private:
		std::shared_ptr<Node<T>> put(std::shared_ptr<Node<T>> node_ptr, std::string& key, T value, int index);
		std::shared_ptr<T> get(std::shared_ptr<Node<T>> node_ptr, std::string& key, int index);
		std::shared_ptr<Node<T>> deleteKey(std::shared_ptr<Node<T>> node_ptr, std::string& key, int index);
	};

	template<typename T>
	void TrieST<T>::put(std::string& key, T& value) {
		total++;
		root = put(root, key, value, 0);
	}

	template<typename T>
	std::shared_ptr<T> TrieST<T>::get(std::string& key) {
		return get(root, key, 0);
	}

	template<typename T>
	std::shared_ptr<Node<T>> TrieST<T>::put(std::shared_ptr<Node<T>> node_ptr, std::string& key, T value, int index) {
		if (node_ptr == nullptr) {
			node_ptr = std::make_shared<Node<T>>(this->R);
		}
		if (index == key.length()) { // 注意root不存储数据
			node_ptr->value = std::make_shared<T>(value);
			return node_ptr;
		}
		char c = key[index];
		node_ptr->next_ptrs[c] = put(node_ptr->next_ptrs[c], key, value, index + 1);

		return node_ptr;
	}

	template<typename T>
	std::shared_ptr<T> TrieST<T>::get(std::shared_ptr<Node<T>> node_ptr,std::string& key, int index) {
		if (node_ptr == nullptr) {
			return nullptr;
		}
		if (index == key.length()) {
			if (node_ptr->value != nullptr) {
				return node_ptr->value;
			}
		}
		char c = key[index];
		return get(node_ptr->next_ptrs[c], key, index + 1);
	}

	template<typename T>
	void TrieST<T>::deleteKey(std::string& key) {
		deleteKey(root, key, 0);
	}

	template<typename T>
	std::shared_ptr<Node<T>>
	TrieST<T>::deleteKey(std::shared_ptr<Node<T>> node_ptr, std::string& key, int index) {
		if (node_ptr == nullptr) {
			return nullptr;
		}
		if (index == key.length()) {
			node_ptr->value = nullptr;
		}
		else {
			char c = key[index];
			node_ptr->next_ptrs[c] = deleteKey(node_ptr->next_ptrs[c], key, index + 1);
		}

		if (node_ptr->value != nullptr) {	
			return node_ptr;
		}
		for (auto ptr : node_ptr->next_ptrs) {
			if (ptr != nullptr) {
				return node_ptr;
			}
		}
		return nullptr;
	}
}