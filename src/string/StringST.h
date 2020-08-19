#pragma once
#include <memory>
#include <string>
#include <vector>
namespace code047 {
	template <typename T>
	struct Node {
		std::shared_ptr<T> value;
		int R;
		std::vector<std::shared_ptr<Node<T>>> next_ptrs;
		Node(const int R) : R(R){
			next_ptrs.resize(R,nullptr);
		}
	};

	template <typename T>
	class StringST {
	public:
		StringST() {};
		virtual ~StringST() {}
	public:
		StringST(const StringST&) = delete;
		StringST& operator=(const StringST&) = delete;
	public:
		virtual void put(std::string& key, T& value) = 0;
		virtual std::shared_ptr<T> get(std::string& key) = 0;
		virtual int size() = 0;
		virtual void deleteKey(std::string& key) = 0;
	public:
		bool contains(const std::string& key) {
			return get(key) != nullptr;
		}
		virtual std::vector<std::string> keys() = 0;
		bool empty() {
			return size() == 0;
		}
	public:
		virtual std::string longestKeyPrefixOf(std::string& s) = 0;
		virtual std::vector<std::string > keysWithPrefix(std::string& s) = 0;
		virtual std::vector<std::string> keysThatMath(std::string& s) = 0;
	};

	
}