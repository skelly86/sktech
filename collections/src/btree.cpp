/*
 * btree.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: Shauna
 */
#ifndef BTREE_CPP_
#define BTREE_CPP_
#include"includes/btree.h"
namespace sktech {
	template<class T, class K = unsigned int>
	btree<T,K>::btree();
	template<class T, class K = unsigned int>
	btree<T,K>::btree(const T &value, const K &newKey);
	template<class T, class K = unsigned int>
	btree<T,K>::btree(const btree &otherTree) {
		basic_tree<T,K>::basic_tree(otherTree);
		copy(otherTree);
	}
	template<class T, class K = unsigned int>
	btree<T,K>::~btree() {
		basic_tree<T,K>::~basic_tree();
	}
	template<class T, class K = unsigned int>
	void btree<T,K>::clear() {
		purge(root);
	}
	template<class T, class K = unsigned int>
	void btree<T,K>::insert(const T &newVal, const K &newKey);
	template<class T, class K = unsigned int>
	const T &btree<T,K>::search(const K &searchKey);
	template<class T, class K = unsigned int>
	void btree<T,K>::copy(const branch &oldBranch, branch *newBranch) {
		newBranch = new branch(oldBranch);
		if(oldBranch->leftP != NULL)
			copy(oldBranch->leftP, newBranch->leftP);
		if(oldBranch->rightP != NULL)
			copy(oldBranch->rightP, newBranch->rightP);
	}
	template<class T, class K = unsigned int>
	branch<T,K> btree<T,K>::climb(const branch *nextBranch, const K &_key);
	template<class T, class K = unsigned int>
	void btree<T,K>::add(const branch *nextBranch, K newKey, T value);
	template<class T, class K = unsigned int>
	void btree<T,K>::purge(branch<T,K> *nextBranch){
		if(nextBranch->leftP != NULL)
			purge(nextBranch->leftP);
		if(nextBanch->rightP != NULL)
			purge(nextBranch->rightP);
		delete nextBranch;
	}
}
#endif
