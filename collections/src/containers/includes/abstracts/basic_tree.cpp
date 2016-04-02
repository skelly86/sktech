/*
 * basic_tree.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: Shauna
 */
#ifndef BASIC_TREE_CPP_
#define BASIC_TREE_CPP_
#include"interfaces/basic_tree.h"
namespace sktech {
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::basic_tree()
	: root(NULL), _size(0) {}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::basic_tree(const basic_tree<T,K> &otherTree)
	: root(NULL), _size(0) {
		copy(otherTree);
	}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::basic_tree(const T &value, const K &newKey)
	: root(new branch(value, newKey)), _size(1) {}
	template<class T, class K = unsigned long int>
	const unsigned int basic_tree<T,K>::size() const{
		return _size;
	}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::~basic_tree() {
		clear();
	}
	template<class T, class K = unsigned long int>
	basic_tree<T,K> &basic_tree<T,K>::operator=
			(const basic_tree<T,K> &otherTree) {
		if(this != *otherTree) {
			purge(root);
			copy(otherTree->root, root);
		}
		return *this;
	}
	template<class T, class K = unsigned long int>
	void basic_tree<T,K>::clear() {
		purge(root);
		root = NULL;
	}
	template<class T, class K = unsigned long int>
	void basic_tree<T,K>::insert(const T &newVal, const K &newKey) {
			add(root, newKey, newVal);
	}
	template<class T, class K = unsigned long int>
	void basic_tree<T,K>::copy
	(basic_tree<T,K>::branch *oldBranch,
	basic_tree<T,K>::branch *newBranch) {
		newBranch = new branch(*oldBranch);
		_size++;
		if(oldBranch->leftP != NULL)
			copy(oldBranch->leftP, newBranch->leftP);
		if(oldBranch->rightP != NULL)
			copy(oldBranch->rightP, newBranch->rightP);
	}
	template<class T, class K = unsigned long int>
	void basic_tree<T,K>::add
	(basic_tree<T,K>::branch *&nextBranch, const K &newKey, const T &value) {
		if(nextBranch == NULL) {
			nextBranch = new branch(value, newKey);
			_size++;
		} else if(nextBranch < newKey)
			add(nextBranch->rightP, newKey, value);
		else
			add(nextBranch->leftP, newKey, value);
	}
	template<class T, class K = unsigned long int>
	void basic_tree<T,K>::purge(basic_tree<T,K>::branch *nextBranch){
		if(nextBranch->leftP != NULL)
			purge(nextBranch->leftP);
		if(nextBranch->rightP != NULL)
			purge(nextBranch->rightP);
		delete nextBranch;
		_size--;
	}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::branch<T,K>::branch()
	:val(NULL), key(0) {}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::branch<T,K>::branch(const T &newVal, const K &newKey)
	: val(new T(newVal)), key(newKey) {}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::branch::branch(const branch &otherBranch)
	: val(new T(otherbranch->val)), key(otherBranch.key) {}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::branch::~branch() {
		node<T>::~node();
		key = K();
	}
	template<class T, class K = unsigned long int>
	basic_tree<T,K>::branch &basic_tree<T,K>::branch::operator=
	(const basic_tree<T,K>::branch &otherBranch) {
		if(this != *otherBranch) {
			node<T>::operator=(otherBranch);
			key = otherBranch.key;
		}
		return *this;
	}
	template<class T, class K = unsigned long int>
	bool basic_tree<T,K>::branch::operator==
	(const basic_tree<T,K>::branch &otherBranch) {
		return key == otherBranch.key;
	}
	template<class T, class K = unsigned long int>
	bool basic_tree<T,K>::branch::operator!=
	(const basic_tree<T,K>::branch &otherBranch) {
		return val != otherBranch.val;
	}
	template<class T, class K = unsigned long int>
	bool basic_tree<T,K>::branch::operator<
	(const basic_tree<T,K>::branch &otherBranch) {
		return val < otherBranch.val;
	}
	template<class T, class K = unsigned long int>
	bool basic_tree<T,K>::branch::operator>
	(const basic_tree<T,K>::branch &otherBranch) {
		return val > otherBranch.val;
	}
}
#endif
