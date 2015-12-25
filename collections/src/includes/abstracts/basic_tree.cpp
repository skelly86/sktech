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
	template<class T, class K>
	basic_tree<T,K>::basic_tree()
	: root(NULL), _size(0) {}
	template<class T, class K>
	basic_tree<T,K>::basic_tree(const basic_tree &otherTree)
	: root(NULL), _size(0) {}
	template<class T, class K>
	const unsigned int basic_tree<T,K>::size() {
		return _size;
	}
	template<class T, class K>
	basic_tree<T,K>::~basic_tree() {
		clear();
	}
	template<class T, class K>
	basic_tree<T,K>::branch::branch()
	:val(NULL), key(0) {}
	template<class T, class K>
	basic_tree<T,K>::branch::branch(const T &newVal, const K &newKey)
	: val(new T(newVal)), key(newKey) {}
	template<class T, class K>
	basic_tree<T,K>::branch::branch(const branch &otherBranch)
	: val(new T(otherbranch->val)), key(otherBranch.key) {}
	template<class T, class K>
	basic_tree<T,K>::branch::~branch() {
		node<T>::~node();
	}
	template<class T, class K>
	basic_tree<T,K>::branch<T,K> &basic_tree<T,K>::branch::operator=(const branch &otherBranch) {
		if(this != *otherBranch) {
			delete val;
			val = new T(otherBranch->val);
			key = otherBranch.key;
		}
		return *this;
	}
	template<class T, class K>
	bool basic_tree<T,K>::branch::operator==(const branch &otherBranch) {
		return key == otherBranch.key;
	}
	template<class T, class K>
	bool basic_tree<T,K>::branch::operator!=(const branch &otherBranch) {
		return val != otherBranch.val;
	}
	template<class T, class K>
	bool basic_tree<T,K>::branch::operator<(const branch &otherBranch) {
		return val < otherBranch.val;
	}
	template<class T, class K>
	bool basic_tree<T,K>::branch::operator>(const branch &otherBranch) {
		return val > otherBranch.val;
	}
}
#endif
