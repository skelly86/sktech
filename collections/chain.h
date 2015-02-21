/*
 * chain.h
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 */
#endif
#ifndef CHAIN_H_
#define CHAIN_H_
#include"node.h"
#include<cstdarg>
namespace sktech {

	/*
	 * Type: chain<T>
	 * Members:
	 *	firstP:Pointer to node<T>:points to address of first node
	 *	lastP:Pointer to node<T>:points to address of last node
	 *	size:Unsigned Integer:current size of the chain
	 * 	max:Unsigned Integer:optional maximum size
	 * Domain:
	 * 	pushFront(val:Constant T Ref):Constant T Ref:pushes new value to front of chain
	 * 	pushBack(val:Constant T Ref):Constant T Ref:pushes new value to back of chain
	 * 	popFront():T:removes node in front of chain, sends old value to user
	 * 	popBack():T:removes node in back of chain, sends old value to user
	 */
	template<class T>
	class chain {
	public:
		chain();
		chain(unsigned newSize);
		chain(unsigned newSize, ...);
		chain(const chain &otherChain);
		virtual ~chain();
		const T &pushBack(const T &newVal)const;
		const T &pushFront(const T &newVal)const;
		const T &peekFront()const;
		const T &peekBack()const;
		T popFront();
		T popBack();
		const unsigned Size()const;
		const unsigned Max()const;
		bool full()const;
		bool empty()const;
		// Array index operator
		T &operator[](unsigned n);
	private:
		unsigned size, max;
		node<T> *firstP;
		node<T> *lastP;
	};
}
#endif /* CHAIN_H_ */
