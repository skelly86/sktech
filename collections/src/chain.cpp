/*
 * chain.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 *      TODO: Utilize inheritance within lists
 */
#ifndef CHAIN_CPP_
#define CHAIN_CPP_
#include"includes/chain.h"
namespace sktech {
	template<class T>
	chain<T>::chain()
	:_size(0), max(0), firstP(NULL), lastP(NULL){}
	template<class T>
	chain<T>::chain(unsigned new_size)
	:_size(0), max(0), firstP(NULL), lastP(NULL){
		while(_size < new_size)
			push_back(T());}
	template<class T>
	chain<T>::chain(unsigned new_size, ...)
	:_size(0), max(0), firstP(NULL), lastP(NULL){
		va_list newChain;
		va_start(newChain, new_size);
		for(int i = 0; i < new_size; i++)
			push_back(va_arg(newChain, T));
		va_end(newChain);}
	template<class T>
	chain<T>::chain(const chain &otherChain)
	:_size(0), max(otherChain.max), firstP(NULL), lastP(NULL){
		// counter for index
		unsigned i = 0;
		// push otherChain onto this one
		while(_size < otherChain._size)
			push_back(otherChain[i++]);}
	template<class T>
	chain<T>::~chain() {
		while(!empty())
			pop_back();}
	template<class T>
	const T &chain<T>::push_back(const T &newVal)const{
		//set overflow conditions
		if(full())
			throw newVal;
		// Attach to end of list
		if(_size == 0)
			firstP = lastP = new node<T>(newVal);
		else{
			lastP->right = new node<T>(newVal);
			lastP->rightP->leftP = lastP;
			lastP = lastP->rightP;}
		// Increment _size
		_size++;
		return front();}
	template<class T>
	const T &chain<T>::push_front(const T &newVal)const{
		//set overflow conditions
		if(full())
			throw newVal;
		if(empty())
			firstP = lastP = new node<T>(newVal);
		else{
			lastP->leftP = new node<T>(newVal);
			lastP->leftP->rightP = lastP;
			lastP = lastP->leftP;}
		// Increment _size
		_size++;
		return front();}
	// Array index operator
	template<class T>
	T &chain<T>::operator[](unsigned long n) {
		int index = 0;
		// check if in range
		if(n >= _size)
			throw n;//new out_of_range("");
		// check if lower or higher half of chain
		if(n < (_size/2)){
			// traverse list
			for(node<T> *traversalP = firstP;
					index <= n;
					traversalP = traversalP->rightP){
				if(index == n)
					// return the indexed node value
					return *(traversalP->val);
				index++;}
		}
		else{
			index = _size - 1;
			// traverse list
			for(node<T> *traversalP = lastP;
					index <= n;
					traversalP = traversalP->leftP){
				if(index == n)
					// return the indexed node value
					return traversalP->val;
				index--;}
		}
	}
}
#endif // CHIAN_CPP_
