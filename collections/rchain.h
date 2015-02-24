/*
 * TODO impliment the linked list recursively
 */
#ifndef RCHAIN_H_
#define RCHAIN_H_
#include"node.h"
namespace sktech{
	template<class T>
	class rchain {
	public:
		rchain();
		rchain(unsigned newSize);
		rchain(unsigned newSize, ...);
		rchain(const rchain &otherrchain);
		virtual ~rchain();
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
