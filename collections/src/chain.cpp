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
		return newVal;}
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
		return newVal;}
	template<class T>
	const T &chain<T>::front()const{
		return firstP->val;}
	template<class T>
	const T &chain<T>::back()const{
		return lastP->val;}
	template<class T>
	T chain<T>::pop_front() {
		T temp;	//temporary memory for pop
		if(!empty()){
			// detach front node
			node<T> *tempNode = firstP;
			firstP = firstP->rightP;
			// assign value in node to temp
			temp = *(tempNode->val);
			// destroy node
			delete tempNode;
			//decrement _size
			_size--;}
		// return temp
		return temp;}
	template<class T>
	T chain<T>::pop_back() {
		T temp;	//temporary memory for pop
		if(!empty()){
			// detach front node
			node<T> *tempNode = lastP;
			lastP = lastP->rightP;
			// assign value in node to temp
			temp = *(tempNode->val);
			// destroy node
			delete tempNode;
			//decrement _size
			_size--;}
		// return temp
		return temp;}
	template<class T>
	const unsigned chain<T>::size()const{
		return _size;}
	template<class T>
	const unsigned chain<T>::Max()const{
		return max;}
	template<class T>
	bool chain<T>::full()const{
		return max > 0 && _size == max;}
	template<class T>
	bool chain<T>::empty()const{
		return _size == 0;}
	// Array index operator
	template<class T>
	T &chain<T>::operator[](unsigned n) {
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
