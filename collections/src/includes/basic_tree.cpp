/*
 * basic_tree.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: Shauna
 */
#ifndef BASIC_TREE_CPP_
#define BASIC_TREE_CPP_
#include"basic_tree.h"
namespace sktech {
	template<class T, class K>
	basic_tree<T>::basic_tree()
	: root(NULL), _size(0) {}
	template<class T, class K>
	const unsigned int basic_tree<T>::size() {
		return _size;
	}
}
#endif
