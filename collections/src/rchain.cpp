/*
 *
 */
#ifndef RCHAIN_CPP_
#define RCHAIN_CPP_
#include"includes/rchain.h"
namespace sktech{
	template<class T>
	rchain<T>::rchain();
	template<class T>
	rchain<T>::rchain(unsigned newSize);
	template<class T>
	rchain<T>::rchain(unsigned newSize, ...);
	template<class T>
	rchain<T>::rchain(const rchain &otherrchain);
	template<class T>
	rchain<T>::~rchain();
	template<class T>
	const T &rchain<T>::pushBack(const T &newVal)const;
	template<class T>
	const T &rchain<T>::pushFront(const T &newVal)const;
	template<class T>
	const T &rchain<T>::peekFront()const;
	template<class T>
	const T &rchain<T>::peekBack()const;
	template<class T>
	T rchain<T>::popFront();
	template<class T>
	T rchain<T>::popBack();
	template<class T>
	const size_t rchain<T>::Size()const;
	template<class T>
	const size_t rchain<T>::Max()const;
	template<class T>
	bool rchain<T>::full()const;
	template<class T>
	bool rchain<T>::empty()const;
	template<class T>
	T &rchain<T>::operator=(const T &otherChain)
	template<class T>
	T &rchain<T>::operator[](unsigned n);
	template<class T>
	T &rchain<T>::left(node<T> *nextNode, unsigned i, unsigned index){
		if(i == index)
			return nextNode->val;
		return left(nextNode->leftP, i+1, index);
	}
	template<class T>
	T &rchain<T>::right(node<T> *nextNode, unsigned i, unsigned index){
		if(i == index)
			return nextNode->val;
		return right(nextNode->rightP, i+1, index);
	}
}
