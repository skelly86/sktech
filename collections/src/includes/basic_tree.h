/*
 * basic_tree.h
 *
 *  Created on: Dec 19, 2015
 *      Author: Shauna
 *      TODO: implement the abstract class
 */

#ifndef BASIC_TREE_H_
#define BASIC_TREE_H_
#include"node.cpp"
namespace sktech {
	template<class T>
	class basic_tree {
	public:
		virtual basic_tree();
		virtual basic_tree(const basic_tree &otherTree);
		virtual ~basic_tree() = 0;
		const unsigned int size() const;
		virtual void insert(const T & newVal) = 0;
		virtual const T &search();
	protected:
		node<T> *root;
		unsigned int _size;
	private:
	};
}
#endif /* INCLUDES_BASIC_TREE_H_ */
