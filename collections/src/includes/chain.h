/*
 * chain.h
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 */
#ifndef CHAIN_H_
#define CHAIN_H_
#include"node.h"
namespace sktech {

	/*
	 * Type: chain<T>
	 * Members:
	 *	firstP:Pointer to node<T>:points to address of first node
	 *	lastP:Pointer to node<T>:points to address of last node
	 *	_size:Unsigned Integer:current _size of the chain
	 * 	max:Unsigned Integer:optional maximum _size
	 * Domain:
	 * 	push_front(val:Constant T Ref):Constant T Ref:pushes new value to front of chain
	 * 	push_back(val:Constant T Ref):Constant T Ref:pushes new value to back of chain
	 * 	pop_front():T:removes node in front of chain, sends old value to user
	 * 	pop_back():T:removes node in back of chain, sends old value to user
	 */
	template<class T>
	class chain {
	public:
		chain();
		chain(unsigned new_size);
		chain(unsigned new_size, ...);
		chain(const chain &otherChain);
		virtual ~chain();
		const T &push_back(const T &newVal)const;
		const T &push_front(const T &newVal)const;
		const T &front()const;
		const T &back()const;
		T pop_front();
		T pop_back();
		const unsigned size()const;
		const unsigned Max()const;
		bool full()const;
		bool empty()const;
		// Array index operator
		T &operator[](unsigned n);
	private:
		size_t _size, max;
		node<T> *firstP;
		node<T> *lastP;
	};
}
#endif /* CHAIN_H_ */
