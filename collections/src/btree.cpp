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
	btree<T,K>::btree() {
		basic_tree<T,K>::basic_tree();
	}
	template<class T, class K = unsigned int>
	btree<T,K>::btree(const T &value, const K &newKey) {
		bais_tree<T,K>::basic_tree(value, newKey);
	}
	template<class T, class K = unsigned int>
	btree<T,K>::btree(const btree &otherTree) {
		basic_tree<T,K>::basic_tree(otherTree);
		copy(otherTree);
	}
	template<class T, class K = unsigned int>
	btree<T,K>::~btree() {
		clear();
	}
	template<class T, class K = unsigned int>
	btree<T,K> &btree<T,K>::operator=(const btree<T,K> &otherTree) {
		if(this != *otherTree) {
			purge(root);
			copy(otherTree->root, root);
		}
		return *this;
	}
	template<class T, class K = unsigned int>
	void btree<T,K>::clear() {
		purge(root);
		root = NULL;
	}
	template<class T, class K = unsigned int>
	void btree<T,K>::insert(const T &newVal, const K &newKey) {
			add(root, newKey, newVal);
	}
	template<class T, class K = unsigned int>
	const T &btree<T,K>::search(const K &searchKey) {
		return climb(root, searchKey)->val;
	}
	template<class T, class K = unsigned int>
	void btree<T,K>::copy(const branch *oldBranch, branch *newBranch) {
		newBranch = new branch(*oldBranch);
		_size++;
		if(oldBranch->leftP != NULL)
			copy(oldBranch->leftP, newBranch->leftP);
		if(oldBranch->rightP != NULL)
			copy(oldBranch->rightP, newBranch->rightP);
	}
	template<class T, class K = unsigned int>
	branch<T,K> &btree<T,K>::climb
	(const branch<T,K> *nextBranch, const K &_key) {
		if(nextBranch == _key)
			return nextBranch;
		else if(nextBranch < _key)
			return climb(nextBranch->rightP, _key);
		else
			return climb(nextBranch->leftP, _key);
	}
	template<class T, class K = unsigned int>
	void btree<T,K>::add
	(branch<T,K> *nextBranch, const K &newKey, const T &value) {
		if(nextBranch == NULL) {
			nextBranch = new branch(value, newKey);
			_size++;
		} else if(nextBranch < newKey)
			add(nextBranch->rightP, newKey, value);
		else
			add(nextBranch->leftP, newKey, value);
	}
	template<class T, class K = unsigned int>
	void btree<T,K>::purge(branch<T,K> *nextBranch){
		if(nextBranch->leftP != NULL)
			purge(nextBranch->leftP);
		if(nextBanch->rightP != NULL)
			purge(nextBranch->rightP);
		delete nextBranch;
		_size--;
	}
}
#endif
