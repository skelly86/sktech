/*
 * TODO: overload function resize() to take additional arguments
 */
#ifndef RCHAIN_H_
#define RCHAIN_H_
#include"abstracts/basic_chain.cpp"
namespace sktech{
	template<class T>
	class rchain : private basic_chain<T> {
	public:
		rchain();
		rchain(unsigned long int new_size);
		rchain(unsigned long int new_size, ...);
		rchain(const basic_chain<T> &otherChain);
		virtual ~rchain();
		void copy(const basic_chain<T> &otherChain);
		void clear();
		void resize(unsigned long int newSize);
		void resize(unsigned long int args, ...);
		void pop_front(unsigned long int args, ...);
		void pop_back(unsigned long int args, ...);
		basic_chain<T> &operator=(const basic_chain<T> &otherChain);
		T &operator[](unsigned long int n);
	private:
		bool grow(unsigned long int size,
				const basic_chain<T> &otherChain = NULL);
		T &left(node<T> *nextNode, unsigned long int i,
				unsigned long int index);
		T &right(node<T> *nextNode, unsigned long int i,
				unsigned long int index);
		bool varAdd(va_list &newChain, unsigned long int new_size,
				unsigned long int index = 0);
	};
}
