/*
 * lineartree.h
 *
 *  Created on: Feb 11, 2015
 *      Author: shauna
 */
#ifndef RECURSIVESTACK_H_
#define RECURSIVESTACK_H_
#include"node.h"
namespace sktech{
	template<class T>
	class recursive_stack {
	public:
		recursive_stack();
		recursive_stack(unsigned newMax);
		recursive_stack(const recursive_stack<T> &otherStack);
		virtual ~recursive_stack();
		T &push(const T &newVal);
		T pop();
		bool full()const;
		bool empty()const;
		recursive_stack<T> &operator=(const recursive_stack<T> &otherStack);
		T &operator[](unsigned n);
	private:
		//TODO remove node
		bool down(node<T> *child, T *nextVal);
		T &down(node<T> *child, unsigned index, unsigned i);
		T *up(node<T> *child);
		size_t size, max;
		node<T> *root;
	};
}
#endif /* RECURSIVESTACK_H_ */
