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
	itree<T,K>::itree(const itree &otherTree);
	template<class T, class K = unsigned int>
	itree<T,K>::~itree();
	template<class T, class K = unsigned int>
	itree &itree<T,K>::operator=(const itree &otherTree);
	template<class T, class K = unsigned int>
	void itree<T,K>::clear();
	template<class T, class K = unsigned int>
	void itree<T,K>::insert(const T &newVal, const K &newKey);
	template<class T, class K = unsigned int>
	const T &itree<T,K>::search(const K &searchKey);
	template<class T, class K = unsigned int>
	void itree<T,K>::copy(const branch *oldBranch);
	template<class T, class K = unsigned int>
	branch &itree<T,K>::climb(const K &_key);
	template<class T, class K = unsigned int>
	void itree<T,K>::add(const K &newKey, const T &value);
	template<class T, class K = unsigned int>
	void itree<T,K>::purge();
}
#endif
