#pragma once
#include <vector>
#include <memory>
#include <stdlib.h>
namespace code047 {

	// Flip coin to get height between[1, max_level]
	size_t getRandomLevelLessThan(size_t max_level) {
		const double pro = 0.5; // flip coin 
		size_t level = 1;
		while (flipCoin() < pro && level < max_level) {
			level++;
		}
		return level;
	}

	double flipCoin() {
		return std::rand() % double(std::RAND_MAX);
	}
	
	template<typename TKey, typename TValue>
	class SkipListNode {
	public:
		SkipListNode();
		SkipListNode(size_t height) {
			neighbors.resize(height);
		}
		SkipListNode(const TKey& key, const TValue& value, size_t height) :
			key(key), value(value), height(height) {}

		~SkipListNode() {}
	private:
		TKey key;
		TValue value;
		size_t height;
		std::vector<std::shared_ptr<SkipListNode<T>>> neighbors;
	};

	template<typename TKey, typename TValue>
	class SkipList {
	public:
		SkipList() = delete;
		SkipList(const size_t MaxHeight) : MAX_HEIGHT(MaxHeight) {
			head.neighbors.resize(MaxHeight);
		}
	public:
		void add(const TKey& key, const TValue& value);
		std::shared_ptr<TValue> get(const TKey& key);
		void contains(const TKey& key);
		void deleteKey(const TKey& key);
	public:
		size_t count;
		size_t height;
		const size_t MAX_HEIGHT;
		SkipListNode<TKey, TValue> head;
	private:
		std::vector<SkipListNode<T>> updateNodes;
		std::vector<SkipListNode<T>> buildUpdate();
	};



}