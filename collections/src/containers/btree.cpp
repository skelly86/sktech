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
template<class T, class K = unsigned long int>
	btree<T,K>::btree() {
		basic_tree<T,K>::basic_tree();
	}
	template<class T, class K = unsigned long int>
	btree<T,K>::btree(const T &value, const K &newKey) {
		basic_tree<T,K>::basic_tree(value, newKey);
	}
	template<class T, class K = unsigned long int>
	btree<T,K>::btree(const btree &otherTree) {
		basic_tree<T,K>::basic_tree(otherTree);
	}
	template<class T, class K = unsigned long int>
	btree<T,K>::~btree() {
		basic_tree<T,K>::~basic_tree();
	}
	template<class T, class K = unsigned long int>
	basic_tree<T,K> &btree<T,K>::operator=(const basic_tree<T,K> &otherTree) {
		return basic_tree<T,K>::operator=(otherTree);
	}
	template<class T, class K = unsigned long int>
	const T &btree<T,K>::search(const K &searchKey) {
		return *(climb(root, searchKey).val);
	}
	//TODO: Figure out why eclipse has this as a syntax error
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::branch<T,K> &btree<T,K>::climb
	(const branch<T,K> *&nextBranch, const K &_key) {
		if(*nextBranch == _key)
			return *nextBranch;
		else if(*nextBranch < _key)
			return climb(nextBranch->rightP, _key);
		else
			return climb(nextBranch->leftP, _key);
	}
}
#endif
