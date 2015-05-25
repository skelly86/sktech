/*
 * chain.h
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 */
#ifndef CHAIN_H_
#define CHAIN_H_
#include"basic_chain.cpp"
namespace sktech {
	/* TODO: Utilize inheritance within lists
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
	class chain : public basic_chain {
	public:
		chain();
		chain(unsigned new_size);
		chain(unsigned new_size, ...);
		chain(const chain &otherChain);
		virtual ~chain();
		void clear();
		chain &operator=(const chain &otherChain);
		T &operator[](unsigned long n);
	};
}
#endif /* CHAIN_H_ */
