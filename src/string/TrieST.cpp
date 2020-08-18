#include "TrieST.h"

namespace code047 {
	template<typename T>
	TrieST<T>::put(std::string& key, T& value) {
		root = put(root, key, value, 0);
	}

	template<typename T>
	std::shared_ptr<Node<T>> 
	TrieST<T>::put(std::shared_ptr<Node<T>> node_ptr, std::string& key, T value, int index) {
		if (node_ptr == nullptr) {
			node_ptr = std::make_shared<Node<T>>(value, this->R);
		}
		if (index == key.length()) { // 注意root不存储数据
			return x;
		}
		char c = key[index];
		node_ptr->next_ptrs[c] = put(node_ptr->next_ptrs[c], key, value, index + 1);

		return node_ptr;
	}
}