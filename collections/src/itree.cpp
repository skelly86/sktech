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
		copy(otherTree.root);
	}
	template<class T, class K = unsigned int>
	itree<T,K>::~itree() {
		purge();
	}
	template<class T, class K = unsigned int>
	itree &itree<T,K>::operator=(const itree &otherTree) {
		if(this != *otherTree) {
			purge();
			copy(otherTree.root);
		}
		return *this;
	}
	template<class T, class K = unsigned int>
	void itree<T,K>::clear() {
		purge();
	}
	template<class T, class K = unsigned int>
	void itree<T,K>::insert(const T &newVal, const K &newKey) {
		add(newKey, newVal);
	}
	template<class T, class K = unsigned int>
	const T &itree<T,K>::search(const K &searchKey) {
		return climb(searchKey).val;
	}
	template<class T, class K = unsigned int>
	void itree<T,K>::copy(const branch *oldBranch) {

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
		return current;
	}
	template<class T, class K = unsigned int>
	void itree<T,K>::add(const K &newKey, const T &value) {

	}
	template<class T, class K = unsigned int>
	void itree<T,K>::purge() {

	}
}
#endif
