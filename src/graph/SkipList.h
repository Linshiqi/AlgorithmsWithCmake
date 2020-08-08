/*************************************************************************
Function:	SkipList implementaion

Date:		2020/08/08	

Author:		code047

Time complexity:	O(logn) in average, O(n) in worst case

Space complexity:	O(n) -> n+n/2+n/4+...+2+1
**************************************************************************/

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
			this->head = std::make_shared<SkipListNode<TKey, TValue>>(key, value, h);
		}
		~SkipList() {
		}
	public:
		/// <summary>
		/// Add (key, value) pair to skiplist
		/// </summary>
		/// <param name="key"></param>
		/// <param name="value"></param>
		void add(const TKey& key, const TValue& value);

		/// <summary>
		/// Get value by key
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		std::shared_ptr<TValue> get(const TKey& key);

		/// <summary>
		/// If skiplist contains key
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		bool contains(const TKey& key);

		/// <summary>
		/// Delete node by key
		/// </summary>
		/// <param name="key"></param>
		void deleteKey(const TKey& key);
	public:
		size_t count;		// total elements in skiplist
		size_t MaxHeight;	// the height of skiplist

		// head  of skiplist, it doesn't store actual key and value.
		// It's always our start point
		std::shared_ptr<SkipListNode<TKey, TValue>> head;	
	public:
		size_t height() {
			return this->head->height;
		}
	private:
		 /// <summary>
		 /// Build nodes that need update reference
		 /// </summary>
		 /// <param name="key"></param>
		 /// <returns></returns>
		 vsknd_ptr buildUpdate(TKey key);
	};

	template<typename TKey, typename TValue>
	typename SkipList<TKey, TValue>::vsknd_ptr SkipList<TKey, TValue>::buildUpdate(TKey key) {
		SkipList<TKey, TValue>::vsknd_ptr updates;
		std::shared_ptr<SkipListNode<TKey, TValue>> current_ptr = head; // start point
		for (int i = height() - 1; i >= 0; i--) {	// from heigh level to low
			while (current_ptr->neighbors_ptr[i] != nullptr && current_ptr->neighbors_ptr[i]->key < key) { // from left to right
				current_ptr = current_ptr->neighbors_ptr[i];
			}
			updates.push_back(current_ptr);
		}
	
		// Make sure updates[0] is the pre node of key node
		std::reverse(updates.begin(), updates.end());
		return updates;
	}

	template<typename TKey, typename TValue>
	void SkipList<TKey, TValue>::add(const TKey& key, const TValue& value) {
		SkipList<TKey, TValue>::vsknd_ptr updates_ptr;
		updates_ptr = buildUpdate(key);
		std::shared_ptr<SkipListNode<TKey, TValue>> preNode_ptr = updates_ptr[0];

		// If exist, just return
		if (preNode_ptr->neighbors_ptr[0] != nullptr && preNode_ptr->neighbors_ptr[0]->key == key) {
			return;
		}

		// New a node with height()+1 as it's max height
		std::shared_ptr<SkipListNode<TKey, TValue>> newNode =
			std::make_shared<SkipListNode<TKey, TValue>>(key, value, height() + 1);

		// Increase count
		this->count++;

		// Check if height of skiplist needs update
		if (this->head->height < newNode->height) {
			this->head->increHeight();
			this->head->neighbors_ptr[this->head->height - 1] = newNode;
		}

		// Update reference of nodes
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
	std::shared_ptr<TValue> SkipList<TKey, TValue>::get(const TKey& key) {
		std::shared_ptr<SkipListNode<TKey, TValue>> current_ptr = head;
		for (int i = this->head->height - 1; i >= 0; i--) {
			while (current_ptr->neighbors_ptr[i] != nullptr) {
				if (current_ptr->neighbors_ptr[i]->key < key) {
					current_ptr = current_ptr->neighbors_ptr[i];
				}
				else if (current_ptr->neighbors_ptr[i]->key == key) {
					return std::make_shared<TValue>(current_ptr->neighbors_ptr[i]->value);
				}
				else {
					break;
				}
			}
		}
		return nullptr;
	}
	
	template<typename TKey, typename TValue>
	void SkipList<TKey, TValue>::deleteKey(const TKey &key) {
		SkipList<TKey, TValue>::vsknd_ptr updates_ptr;
		updates_ptr = buildUpdate(key);
		std::shared_ptr<SkipListNode<TKey, TValue>> preNode_ptr = updates_ptr[0];
		if (preNode_ptr->neighbors_ptr[0] != nullptr && preNode_ptr->neighbors_ptr[0]->key == key) {
			// Find target
			this->count--;

			// Update nodes references from low to high
			for (int i = 0; i < this->height();i++) {
				if (updates_ptr[i]->neighbors_ptr[i] != nullptr && updates_ptr[i]->neighbors_ptr[i]->key == key) {
					updates_ptr[i]->neighbors_ptr[i] = updates_ptr[i]->neighbors_ptr[i]->neighbors_ptr[i];
				}
				else {
					break;
				}
			}

			// Check if height of skiplist needs update
			if (this->head->neighbors_ptr[this->head->height - 1] == nullptr) {
				this->head->decreHeight();
			}
		}
	}

}