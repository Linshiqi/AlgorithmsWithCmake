/***********************************************************************************
Function:	Implementation of tries

Date:		2020/08/20

Author:		code047

Properties of tries:
1.	Data Structure
		The linked structure(shape) of a trie is indenpendent of the 
		key insertion/deletion: there is a unique trie for any given set of keys.
2.  Search hit:
		The number of array accesses when searching in a trie or inserting a key 
		into a trie is at most 1 plus the length of the key.
3.	Search miss:
		LogR^N
4.	Space:
		The number of links in a tries is between RN and RNW,
		where w is the average key length.
************************************************************************************/
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
		std::string longestKeyPrefixOf(std::string& s) override;
		std::vector<std::string > keysWithPrefix(std::string& s) override;
		std::vector<std::string> keysThatMatch(std::string& pat) override;

		std::vector<std::string> keys() override;
	private:
		std::shared_ptr<Node<T>> root;
		const int R = 127;
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
		std::shared_ptr<Node<T>> get(std::shared_ptr<Node<T>> node_ptr, std::string& key, int index);
		std::shared_ptr<Node<T>> deleteKey(std::shared_ptr<Node<T>> node_ptr, std::string& key, int index);
		
		void collect(std::shared_ptr<Node<T>> node_ptr, std::string pre, std::vector<std::string>& res);
		void collect(std::shared_ptr<Node<T>> node_ptr, std::string pre, std::string& pat, std::vector<std::string>& res);

		int search(std::shared_ptr<Node<T>> node_ptr, std::string s, int index, int length);
	};
	

	template<typename T>
	void TrieST<T>::put(std::string& key, T& value) {
		total++;
		root = put(root, key, value, 0);
	}

	template<typename T>
	std::shared_ptr<T> TrieST<T>::get(std::string& key) {
		auto node_ptr = get(root, key, 0);
		if (node_ptr == nullptr) {
			return nullptr;
		}
		else {
			return node_ptr->value;
		}
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
	std::shared_ptr<Node<T>> TrieST<T>::get(std::shared_ptr<Node<T>> node_ptr,std::string& key, int index) {
		if (node_ptr == nullptr) {
			return nullptr;
		}
		if (index == key.length()) {
			return node_ptr;
		}
		char c = key[index];
		return get(node_ptr->next_ptrs[c], key, index + 1);
	}

	template<typename T>
	void TrieST<T>::deleteKey(std::string& key) {
		total--;
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

	template<typename T>
	void TrieST<T>::collect(std::shared_ptr<Node<T>> node_ptr, std::string pre, std::vector<std::string>& res) {
		if (node_ptr == nullptr) {
			return;
		}
		if (node_ptr->value != nullptr) {
			res.push_back(pre);
		}
		for (int i = 0; i < R; i++) {
			//char c = i;
			std::string s = pre;
			s.push_back(i);
			collect(node_ptr->next_ptrs[i], s, res);
		}
	}

	template<typename T>
	std::vector<std::string > TrieST<T>::keysWithPrefix(std::string& pre) {
		// Use get to find pre last character position as root node, then collect all string with that root
		std::shared_ptr<Node<T>> preRoot = get(root, pre, 0);
		std::vector<std::string> res;
		collect(preRoot, pre, res);
		return res;
	}

	template<typename T>
	std::vector<std::string> TrieST<T>::keys() {
		std::string pre("");
		return keysWithPrefix(pre);
	}

	template<typename T>
	void TrieST<T>::collect(std::shared_ptr<Node<T>> node_ptr, std::string pre, std::string& pat, std::vector<std::string>& res) {
		size_t d = pre.length();
		if (node_ptr == nullptr) {
			return;
		}
		if (pat.length() == d && node_ptr->value != nullptr) {
			res.push_back(pre);
		}
		if (pat.length() == d) {
			return;
		}

		char next = pat[d];
		for (char i = 0; i < R; i++) {
			if (next == '*' || next == i) {
				std::string s = pre;
				s.push_back(i);
				collect(node_ptr->next_ptrs[i], s, pat, res);
			}
		}
	}

	template<typename T>
	std::vector<std::string> TrieST<T>::keysThatMatch(std::string& pat) {
		std::vector<std::string> res;
		collect(root, "", pat, res);
		return res;
	}

	template<typename T>
	int TrieST<T>::search(std::shared_ptr<Node<T>> node_ptr, std::string s, int index, int length) {
		if (node_ptr == nullptr) {
			return length;
		}
		if (node_ptr->value != nullptr) {
			length = index;
		}
		if (s.length() == index) {
			return length;
		}
		return search(node_ptr->next_ptrs[s[index]],s, index + 1, length);
	}

	template<typename T>
	std::string TrieST<T>::longestKeyPrefixOf(std::string& s) {
		int length = search(root, s, 0, 0);
		return s.substr(0, length);
	}
}