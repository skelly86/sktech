/*
 * chain.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 *      TODO: overload function resize() to take additional arguments
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
		handle_args(new_size, newChain, true);
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
	void chain<T>::resize(unsigned long int newSize) {
		if(_max < newSize)
			_max = newSize;
		while(_size < newSize)
			push_back(T());
	}
	template<class T>
	void chain<T>::resize(unsigned long int args, ...) {
		if(_max < _size + args)
			_max = _size + args;
		va_list newChain;
		handle_args(args, newChain, true);
	}
	template<class T>
	void chain<T>::push_front(unsigned long int args, ...) {
		va_list newChain;
		handle_args(args, newChain);
	}
	template<class T>
	void chain<T>::push_back(unsigned long int args, ...) {
		va_list newChain;
		handle_args(args, newChain, true);
	}
	template<class T>
	void chain<T>::clear() {
		while(!empty())
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
		if(n >= basic_chain<T>::_size)
			throw n;//new out_of_range("");
		if(n < _size / 2)
			return traverse(n, true);
		else
			return traverse(n, false);
	}
	template<class T>
	void chain<T>::handle_args(unsigned long int argc,
			va_list &argv,
			bool end = 0x00) {
		va_start(argv, argc);
		unsigned long int i = 0;
		if(end)
			while(i < argc) {
				push_front(va_arg(argv, T));
				i++;
			}
		else
			while(i < argc) {
				push_back(va_arg(argv, T));
				i++;
			}
		va_end(argv);
	}
	template<class T>
	T &chain<T>::traverse(unsigned long int n, bool lower) {
		unsigned long int index = lower ? 0 : _size - 1;
		node<T> *traversalP = lower ? firstP : lastP;
		do {
			if(index == n)
				return traversalP->val;
			index += lower ? 1 : -1;
			traversalP = lower ? traversalP->rightP : traversalP->leftP;
		} while(traversalP != NULL);
	}
}
#endif // CHIAN_CPP_
