/*
 * TODO impliment the linked list recursively
 */
#ifndef RCHAIN_H_
#define RCHAIN_H_
// TODO this to NULL on the other header files
#ifndef NULL
#define NULL 0
#include"node.h"
namespace sktech{
	template<class T>
	class rchain {
	public:
		rchain();
		rchain(unsigned newSize);
		rchain(unsigned newSize, ...);
		rchain(const rchain &otherChain);
		virtual ~rchain();
		const T &pushBack(const T &newVal)const;
		const T &pushFront(const T &newVal)const;
		const T &peekFront()const;
		const T &peekBack()const;
		T popFront();
		T popBack();
		const size_t Size()const;
		const size_t Max()const;
		bool full()const;
		bool empty()const;
		T &operator=(const T &otherChain)
		T &operator[](unsigned n);
	private:
		T &left(node<T> *nextNode, unsigned i, unsigned index);
		T &right(node<T> *nextNode, unsigned i, unsigned index);
		size_t size, max;
		node<T> *firstP;
		node<T> *lastP;
	};
}
