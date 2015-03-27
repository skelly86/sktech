/*
 * TODO impliment the linked list recursively
 */
#ifndef RCHAIN_H_
#define RCHAIN_H_
#include<cstdarg>
#include"node.h"
namespace sktech{
	template<class T>
	class rchain{
	public:
		rchain();
		rchain(unsigned new_size);
		rchain(unsigned new_size, ...);
		rchain(const rchain<T> &otherChain);
		virtual ~rchain();
		void clear();
		void push_back(const T &newVal)const;
		void push_front(const T &newVal)const;
		const T &front()const;
		const T &back()const;
		void pop_front();
		void pop_back();
		const size_t size()const;
		const size_t Max()const;
		bool full()const;
		bool empty()const;
		rchain<T> &operator=(const rchain<T> &otherChain)
		T &operator[](unsigned n);
	private:
		bool grow(unsigned _size, const rchain<T> &otherChain = NULL, unsigned index = 0);
		T &left(node<T> *nextNode, unsigned i, unsigned index);
		T &right(node<T> *nextNode, unsigned i, unsigned index);
		bool add(node<T> *addPoint, const T &newVal, bool first);
		bool varAdd(va_list &newChain, unsigned new_size, unsigned index = 0);
		bool remove(node<T> *deletePoint, bool first);
		size_t _size, max;
		node<T> *firstP, *lastP;
	};
}
