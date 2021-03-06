/*
 * @author: Shauna Kelly
 * TODO: overload function resize() to take additional arguments
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
		copy(otherChain);
	}
	template<class T>
	rchain<T>::~rchain() {
		clear();
	}
	template<class T>
	void rchain<T>::copy(const basic_chain<T> &otherChain) {
		if(!empty)
			clear();
		grow(otherChain._size, otherChain);
	}
	template<class T>
	void rchain<T>::clear() {
		if(empty())
			_max = 0;
		else {
			basic_chain<T>::pop_front();
			clear();
		}
	}
	template<class T>
	void rchain<T>::resize(unsigned long int newSize) {
		if(_max < newSize)
			_max = newSize;
			grow(newSize - _size);
	}
	// TODO: fix these functions.
	template<class T>
	void rchain<T>::resize(unsigned long int args, ...) {
		va_list newVals;
		va_start(newVals, args);
		varAdd(newVals, args + _size, _size - 1);
		va_end();
	}
	template<class T>
	void rchain<T>::push_front(unsigned long int args, ...) {
		va_list newVals;
		va_start(newVals, args);
		varAddFront(newVals, args);
		va_end();
	}
	template<class T>
	void rchain<T>::push_back(unsigned long int args, ...) {
		va_list newVals;
		va_start(newVals, args);
		varAddBack(newVals, args);
		va_end();
	}
	template<class T>
	basic_chain<T> &rchain<T>::operator=(const basic_chain<T> &otherChain) {
		if(this != *otherChain)
			copy(otherChain);
		return *this;
	}
	template<class T>
	T &rchain<T>::operator[](unsigned long int n) {
		if(n > _size)
			throw n;
		if(n > _size / 2)
			return left(lastP, _size - 1, n);
		return right(firstP, 0, n);
	}
	template<class T>
	bool rchain<T>::grow(unsigned long int size,
			const basic_chain<T> &otherChain = NULL) {
		if(full())
			return false;
		if(_size != size) {
			if(&otherChain == NULL)
				push_back(T());
			else
				push_back(otherChain[_size + 1]);
			return grow(size, otherChain);
		}
		return true;
	}
	template<class T>
	T &rchain<T>::left(node<T> *nextNode,
			unsigned long int i,
			unsigned long int index) {
		if(i == index)
			return *(nextNode->val);
		return left(nextNode->leftP, i - 1, index);
	}
	template<class T>
	T &rchain<T>::right(node<T> *nextNode,
			unsigned long int i,
			unsigned long int index) {
		if(i == index)
			return *(nextNode->val);
		return right(nextNode->rightP, i + 1, index);
	}
	template<class T>
	bool rchain<T>::varAdd(va_list &newChain,
			unsigned long int new_size,
			unsigned long int index = 0) {
		if(index == new_size)
			return true;
		push_back(va_arg(newChain,T));
		return varAdd(newChain, new_size, index + 1);
	}
	//TODO: fix this
	template<class T>
	bool rchain<T>::varAddFront(va_list &newChain,
			unsigned long int args,
			unsigned long int index = 0) {
		if(args == index)
			return true;
		push_front(va_arg(newChain, T));
		return varAdd(newChain, args, index + 1);
	}
	template<class T>
	bool rchain<T>::varAddBack(va_list &newChain,
			unsigned long int args,
			unsigned long int index = 0) {
		if(args == index)
			return true;
		push_back(va_arg(newChain, T));
		return varAdd(newChain, args, index + 1);
	}
}
#endif
