/*
 * chain.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 */
#ifndef CHAIN_CPP_
#define CHAIN_CPP_
#include"includes/chain.h"
namespace sktech {
	template<class T>
	chain<T>::chain() {
		basic_chain<T>::basic_chain();
	}
	template<class T>
	chain<T>::chain(unsigned long int newSize) {
		basic_chain<T>::basic_chain();
		while(_size < newSize)
			push_back(T());
	}
	template<class T>
	chain<T>::chain(unsigned long int newSize, unsigned long int newMax)
	: firstP(NULL), lastP(NULL), _size(0), _max(newMax) {
		if(newSize > newMax)
			throw this;
		while(_size < newSize)
			pushback(T());
	}
	template<class T>
	chain<T>::chain(unsigned long int new_size, ...) {
		basic_chain<T>::basic_chain();
		va_list newChain;
		va_start(newChain, new_size);
		for(int i = 0; i < new_size; i++)
			push_back(va_arg(newChain, T));
		va_end(newChain);
	}
	template<class T>
	chain<T>::chain(const basic_chain<T> &otherChain) {
		basic_chain<T>::basic_chain();
		copy(otherChain);
	}
	template<class T>
	chain<T>::~chain() {
		clear();
	}
	template<class T>
	void chain<T>::copy(const basic_chain<T> &otherChain) {
		if(!empty())
			clear();
		for(unsigned long int i = 0; i < otherChain.size(); i++)
			push_back(otherChain[i]);
	}
	template<class T>
	void chain<T>::clear() {
		while(!basic_chain<T>::empty())
			basic_chain<T>::pop_back();
		_max = 0;
	}
	template<class T>
	basic_chain<T> &chain<T>::operator=(const basic_chain<T> &otherChain) {
		if(this != *otherChain)
			copy(otherChain);
		return *this;
	}
	template<class T>
	T &chain<T>::operator[](unsigned long int n) {
		int index = 0;
		// check if in range
		if(n >= basic_chain<T>::_size)
			throw n;//new out_of_range("");
		// check if lower or higher half of chain
		if(n < (basic_chain<T>::_size/2)) {
			// traverse list
			for(node<T> *traversalP = basic_chain<T>::firstP;
					index <= n;
					traversalP = traversalP->rightP) {
				if(index == n)
					// return the indexed node value
					return *(traversalP->val);
				index++;
			}
		}
		else {
			index = basic_chain<T>::_size - 1;
			// traverse list
			for(node<T> *traversalP = basic_chain<T>::lastP;
					index <= n;
					traversalP = traversalP->leftP) {
				if(index == n)
					// return the indexed node value
					return traversalP->val;
				index--;
			}
		}
	}
}
#endif // CHIAN_CPP_
