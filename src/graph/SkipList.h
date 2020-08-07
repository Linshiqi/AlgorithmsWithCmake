#pragma once
#include <vector>
#include <functional>
#include <stdlib.h>
#include <algorithm>
namespace code047 {

	double flipCoin() {
		return std::rand() / double(RAND_MAX);
	}

	// Flip coin to get height between[1, max_level]
	size_t getRandomLevelLessThan(size_t max_level) {
		const double pro = 0.5; // flip coin 
		size_t level = 1;
		while (flipCoin() < pro && level < max_level) {
			level++;
		}
		return level;
	}

	template<typename TKey, typename TValue>
	class SkipListNode {
	public:
		SkipListNode(): SkipListNode(2) {
		};
		SkipListNode(size_t height) {
			size_t h = getRandomLevelLessThan(height);
			this->height = h;

			neighbors.resize(h, nullptr);
		}
		SkipListNode(const TKey& key, const TValue& value, size_t height) :
			key(key), value(value), height(height) {
			size_t h = getRandomLevelLessThan(height);
			this->height = h;
			neighbors.resize(h, nullptr);
		}



		~SkipListNode() {
			for (auto p : neighbors) {
				delete p;
			}
		}
	public:
		TKey key;
		TValue value;
		size_t height;
		std::vector<SkipListNode<TKey, TValue>*> neighbors;
		void increHeight() {
			this->neighbors.push_back(nullptr);
			this->height++;
		}
		void decreHeight() {
			this->neighbors.pop_back();
			this->height--;
		}
	};

	template<typename TKey, typename TValue>
	class SkipList {
	public:
		SkipList() : SkipList(2){
		}
		SkipList(const size_t MaxHeight) : MAX_HEIGHT(MaxHeight) {
			this->count = 0;
			size_t h = getRandomLevelLessThan(MaxHeight);
			this->head.height = h;
			this->head.neighbors.resize(h, nullptr);
		}

		~SkipList() {
			for (auto p : updateNodes) {
				delete p;
			}
		}
	public:
		void add(const TKey& key, const TValue& value);
		TValue* get(const TKey& key);
		bool contains(const TKey& key);
		void deleteKey(const TKey& key);
	public:
		size_t count;
	
		const size_t MAX_HEIGHT = 2;
		SkipListNode<TKey, TValue> head;
		size_t height() {
			return this->head.height;
		}
	private:
		std::vector<SkipListNode<TKey, TValue>*> updateNodes;
		std::vector<SkipListNode<TKey, TValue>*> buildUpdate(TKey key);
	};

	template<typename TKey, typename TValue>
	std::vector<SkipListNode<TKey, TValue>*> SkipList<TKey, TValue>::buildUpdate(TKey key) {
		std::vector<SkipListNode<TKey, TValue>*> updates;
		SkipListNode<TKey, TValue>* current_ptr = &head;
		for (int i = height() - 1; i >= 0; i--) {
			while (current_ptr->neighbors[i] != nullptr && current_ptr->neighbors[i]->key < key) {
				current_ptr = current_ptr->neighbors[i];
			}
			updates.push_back(current_ptr);
		}
	/*	std::vector<SkipListNode<TKey, TValue>*> tmp;
		for (int i = 0; i < updates.size(); i++) {
			tmp[i] = updates[updates.size() - 1 - i];
		}*/
		
		std::reverse(updates.begin(), updates.end());
		return updates;
	}

	template<typename TKey, typename TValue>
	void SkipList<TKey, TValue>::add(const TKey& key, const TValue& value) {
		size_t currentHeight = height();
		std::vector<SkipListNode<TKey, TValue>*> updates_ptr;
		updates_ptr = buildUpdate(key);
		if (updates_ptr[0] != nullptr && updates_ptr[0]->key == key) {
			return;
		}

		SkipListNode<TKey, TValue> *newNode = new SkipListNode<TKey, TValue>(key, value, height() + 1);
		this->count++;
		if (this->head.height < newNode->height) {
			this->head.increHeight();
			this->head.neighbors[this->head.height - 1] = newNode;
		}
		for (int i = 0;i < newNode->height;i++) {
			if (i < updates_ptr.size()) {
				newNode->neighbors[i] = updates_ptr[i]->neighbors[i];
				updates_ptr[i]->neighbors[i] = newNode;
			}
		}
	}

	template<typename TKey, typename TValue>
	bool SkipList<TKey, TValue>::contains(const TKey& key) {
		bool res = false;
		SkipListNode<TKey, TValue>* current_ptr = &head;
		for (int i = this->head.height - 1;i >= 0;i--) {
			while (current_ptr->neighbors[i] != nullptr) {
				if (current_ptr->neighbors[i]->key < key) {
					current_ptr = current_ptr->neighbors[i];
				}
				else if (current_ptr->neighbors[i]->key == key) {
					return true;
				}
				else {
					break;
				}
			}
		}
		return res;
	}
	
	template<typename TKey, typename TValue>
	TValue* SkipList<TKey, TValue>::get(const TKey& key) {

	}
	//TValue* SkipList<TKey, TValue>::get(const TKey& key) {

	//}


}