/*
 * TODO impliment the linked list recursively
 */
#ifndef RCHAIN_H_
#define RCHAIN_H_
#include<cstdarg>
#include"node.h"
namespace sktech{
	template<class T>
	class rchain {
	public:
		rchain();
		rchain(unsigned newSize);
		rchain(unsigned newSize, ...);
		rchain(const rchain<T> &otherChain);
		virtual ~rchain();
		void clear();
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
		rchain<T> &operator=(const rchain<T> &otherChain)
		T &operator[](unsigned n);
	private:
		bool grow(unsigned size, const rchain<T> &otherChain = NULL, unsigned index = 0);
		T &left(node<T> *nextNode, unsigned i, unsigned index);
		T &right(node<T> *nextNode, unsigned i, unsigned index);
		bool add(node<T> *addPoint, const T &newVal, bool first);
		bool varAdd(va_list &newChain, unsigned newSize, unsigned index = 0);
		bool remove(node<T> *deletePoint, bool first);
		size_t size, max;
		node<T> *firstP, *lastP;
	};
}
