/*
 * chain.h
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 *      TODO: overload function resize() to take additional arguments
 */
#ifndef CHAIN_H_
#define CHAIN_H_
#include"abstracts/basic_chain.cpp"
namespace sktech {
	/*
	 * Type: chain<T>
	 * Members:
	 *	firstP:Pointer to node<T>:points to address of first node
	 *	lastP:Pointer to node<T>:points to address of last node
	 *	_size:Unsigned Integer:current size of the chain
	 * 	max:Unsigned Integer:optional maximum size
	 * Domain:
	 * 	push_front(val:Constant T Ref):Constant T Ref:pushes new value to front of chain
	 * 	push_back(val:Constant T Ref):Constant T Ref:pushes new value to back of chain
	 * 	pop_front():T:removes node in front of chain, sends old value to user
	 * 	pop_back():T:removes node in back of chain, sends old value to user
	 */
	template<class T>
	class chain : public basic_chain<T> {
	public:
		chain();
		chain(unsigned long int newSize);
		chain(unsigned long int newSize, unsigned long int newMax);
		chain(unsigned long int newSize, ...);
		chain(const basic_chain<T> &otherChain);
		virtual ~chain();
		void clear();
		void copy(const basic_chain<T> &otherChain);
		void resize(unsigned long int newSize);
		void resize(unsigned long int args, ...);
		void push_front(unsigned long int args, ...);
		void push_back(unsigned long int args, ...);
		basic_chain<T> &operator=(const basic_chain<T> &otherChain);
		T &operator[](unsigned long int n);
	private:
		// TODO: implement this function
		void handle_args(unsigned long int argc,
			va_list &argv,
			bool end = 0x00);
		T &traverse(unsigned long int n, bool lower);
	};
}
#endif /* CHAIN_H_ */
