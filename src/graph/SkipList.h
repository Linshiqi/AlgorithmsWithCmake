#pragma once
#include <vector>
#include <functional>
#include <stdlib.h>
#include <algorithm>
#include <memory>
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
		typedef std::vector<std::shared_ptr<SkipListNode<TKey, TValue>>> vsknd_ptr;

		SkipListNode(const TKey& key, const TValue& value, size_t height) :
			key(key), value(value), height(height) {
			size_t h = getRandomLevelLessThan(height);
			this->height = h;
			neighbors_ptr.resize(h, nullptr);
		}

		SkipListNode(const SkipListNode& other) : 
			key(other.key),value(other.value),height(other.height),neighbors_ptr(other.neighbors_ptr) {

		}

		SkipListNode& operator=(const SkipListNode& other) {
			if (this == &other) {
				return *this;
			}
			this->key = other.key;
			this->value = other.value;
			this->neighbors_ptr = other.neighbors_ptr;
			return *this;
		}

		~SkipListNode() {
		}
	public:
		TKey key;
		TValue value;
		size_t height;
		vsknd_ptr neighbors_ptr;
	public:
		//std::vector<SkipListNode<TKey, TValue>*> neighbors;
		void increHeight() {
			this->neighbors_ptr.push_back(nullptr);
			this->height++;
		}
		void decreHeight() {
			this->neighbors_ptr.pop_back();
			this->height--;
		}
	};

	template<typename TKey, typename TValue>
	class SkipList {
	public:
		typedef std::vector<std::shared_ptr<SkipListNode<TKey, TValue>>> vsknd_ptr;

		SkipList(const TKey &key, const TValue &value, const size_t MaxHeight) : MaxHeight(MaxHeight) {
			this->count = 0;
			size_t h = getRandomLevelLessThan(MaxHeight);
			this->head = std::make_shared<SkipListNode<TKey, TValue>>(new SkipListNode(key, value, h));
		}
		~SkipList() {
		}
	public:
		void add(const TKey& key, const TValue& value);
		TValue* get(const TKey& key);
		bool contains(const TKey& key);
		void deleteKey(const TKey& key);
	public:
		size_t count;
		size_t MaxHeight;
		std::shared_ptr<SkipListNode<TKey, TValue>> head;
	public:
		size_t height() {
			return this->head->height;
		}
	private:
		 vsknd_ptr buildUpdate(TKey key);
	};

	template<typename TKey, typename TValue>
	typename SkipList<TKey, TValue>::vsknd_ptr SkipList<TKey, TValue>::buildUpdate(TKey key) {
		SkipList<TKey, TValue>::vsknd_ptr updates;
		std::shared_ptr<SkipListNode<TKey, TValue>> current_ptr = head;
		for (int i = height() - 1; i >= 0; i--) {
			while (current_ptr->neighbors_ptr[i] != nullptr && current_ptr->neighbors_ptr[i]->key < key) {
				current_ptr = current_ptr->neighbors_ptr[i];
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
		SkipList<TKey, TValue>::vsknd_ptr updates_ptr;
		updates_ptr = buildUpdate(key);
		if (updates_ptr[0] != nullptr && updates_ptr[0]->key == key) {
			return;
		}

		std::shared_ptr<SkipListNode<TKey, TValue>> newNode =
			std::make_shared<SkipListNode<TKey, TValue>>(new SkipListNode<TKey, TValue>(key, value, height() + 1));
		this->count++;
		if (this->head->height < newNode->height) {
			this->head->increHeight();
			this->head->neighbors_ptr[this->head->height - 1] = newNode;
		}
		for (int i = 0;i < newNode->height;i++) {
			if (i < updates_ptr.size()) {
				newNode->neighbors_ptr[i] = updates_ptr[i]->neighbors_ptr[i];
				updates_ptr[i]->neighbors_ptr[i] = newNode;
			}
		}
	}

	template<typename TKey, typename TValue>
	bool SkipList<TKey, TValue>::contains(const TKey& key) {
		bool res = false;
		std::shared_ptr<SkipListNode<TKey, TValue>> current_ptr = head;
		for (int i = this->head->height - 1;i >= 0;i--) {
			while (current_ptr->neighbors_ptr[i] != nullptr) {
				if (current_ptr->neighbors_ptr[i]->key < key) {
					current_ptr = current_ptr->neighbors_ptr[i];
				}
				else if (current_ptr->neighbors_ptr[i]->key == key) {
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
		std::shared_ptr<SkipListNode<TKey, TValue>> current_ptr = head;
		for (int i = this->head->height - 1; i >= 0; i--) {
			while (current_ptr->neighbors[i] != nullptr) {
				if (current_ptr->neighbors[i]->key < key) {
					current_ptr = current_ptr->neighbors[i];
				}
				else if (current_ptr->neighbors[i]->key == key) {
					return &current_ptr->neighbors[i]->value;
				}
				else {
					break;
				}
			}
		}
		return nullptr;
	}
	//TValue* SkipList<TKey, TValue>::get(const TKey& key) {

	//}


}