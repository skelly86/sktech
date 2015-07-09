/*
 * TODO: Utilize inheritance within lists
 */
#ifndef RCHAIN_CPP_
#define RCHAIN_CPP_
#include"includes/rchain.h"
namespace sktech {
	template<class T>
	rchain<T>::rchain() {
		basic_chain<T>::basic_chain();
	}
	template<class T>
	rchain<T>::rchain(unsigned long int new_size) {
		basic_chain<T>::basic_chain();
		grow(new_size);
	}
	template<class T>
	rchain<T>::rchain(unsigned long int new_size, ...) {
		basic_chain<T>::basic_chain();
		va_list newChain;
		va_start(newChain, new_size);
		varAdd(newChain, new_size);
		va_end(newChain);
	}
	template<class T>
	rchain<T>::rchain(const basic_chain<T> &otherChain) {
		basic_chain<T>::basic_chain();
		grow(otherChain._size, otherChain);
	}
	template<class T>
	rchain<T>::~rchain() {
		clear();
	}
	template<class T>
	void rchain<T>::clear() {
		if(basic_chain<T>::empty())
			basic_chain<T>::max = 0;
		else {
			basic_chain<T>::pop_front();
			clear();
		}
	}
	template<class T>
	rchain<T> &rchain<T>::operator=(const basic_chain<T> &otherChain) {
		//TODO Implement this operator
		if(this != *otherChain) {
			clear();
			grow(otherChain._size, otherChain);
		}
		return *this;
	}
	template<class T>
	T &rchain<T>::operator[](unsigned long int n) {
		if(n > basic_chain<T>::_size)
			throw n;
		if(n > basic_chain<T>::_size/2)
			return left(basic_chain<T>::lastP, basic_chain<T>::_size - 1, n);
		return right(basic_chain<T>::firstP, 0, n);
	}
	template<class T>
	bool rchain<T>::grow(unsigned _size, const basic_chain<T> &otherChain = NULL, unsigned long int index = 0) {
		//Only used for initialization and assignment
		if(!basic_chain<T>::empty())
			return false;
		if(index + 1 == _size) {
			if(&otherChain == NULL)
				push_back(new T());
			else
				push_back(otherChain[index]);
			return grow(_size, otherChain, index++);
		}
		return true;
	}
	template<class T>
	T &rchain<T>::left(node<T> *nextNode, unsigned long int i, unsigned long int index) {
		if(i == index)
			return *(nextNode->val);
		return left(nextNode->leftP, i-1, index);
	}
	template<class T>
	T &rchain<T>::right(node<T> *nextNode, unsigned long int i, unsigned long int index) {
		if(i == index)
			return *(nextNode->val);
		return right(nextNode->rightP, i+1, index);
	}

	template<class T>
	bool rchain<T>::varAdd(va_list &newChain, unsigned long int new_size, unsigned long int index = 0) {
		if(index == new_size)
			return true;
		push_back(va_arg(newChain,T));
		return varAdd(newChain, new_size, index+1);
	}
}
