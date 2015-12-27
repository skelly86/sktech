/*
 * itree.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: Shauna
 */
#ifndef ITREE_CPP_
#define ITREE_CPP_
#include"includes/itree.h"
namespace sktech {
	template<class T, class K = unsigned int>
	itree<T,K>::itree() {
		basic_tree<T,K>::basic_tree();
	}
	template<class T, class K = unsigned int>
	itree<T,K>::itree(const T &value, const T &newKey) {
		baisc_tree<T,K>::basic_tree(value, newKey);
	}
	template<class T, class K = unsigned int>
	itree<T,K>::itree(const itree &otherTree) {
		basic_tree<T,K>::basic_tree(otherTree);
	}
	template<class T, class K = unsigned int>
	itree<T,K>::~itree() {
		basic_tree<T,K>::~basic_tree();
	}
	template<class T, class K = unsigned int>
	itree &itree<T,K>::operator=(const itree &otherTree) {
		return basic_tree<T,K>::operator=(otherTree);
	}
	template<class T, class K = unsigned int>
	const T &itree<T,K>::search(const K &searchKey) {
		return climb(searchKey).val;
	}
	template<class T, class K = unsigned int>
	branch<T,K> &itree<T,K>::climb(const K &_key) {
		branch<T,K> *current = root;
		while(current != NULL)
			if(_key == current->key)
				return *current;
			else if(_key < current->key)
				current = current->leftP;
			else
				current = current->rightP;
		return *current;
	}
}
#endif
