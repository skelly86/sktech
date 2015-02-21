/*
 * chain.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: shauna
 */
#ifndef CHAIN_CPP_
#define CHAIN_CPP_
#include"chain.h"
namespace sktech {
	template<class T>
	chain<T>::chain()
	:size(0), max(0), firstP(NULL), lastP(NULL){}
	template<class T>
	chain<T>::chain(unsigned newSize)
	:size(0), max(0), firstP(NULL), lastP(NULL){
		while(size < newSize)
			pushBack(T());}
	template<class T>
	chain<T>::chain(unsigned newSize, ...)
	:size(0), max(0), firstP(NULL), lastP(NULL){
		va_list newChain;
		va_start(newChain, newSize);
		for(int i = 0; i < size; i++)
			pushBack(va_arg(newChain, T));}
	template<class T>
	chain<T>::chain(const chain &otherChain)
	:size(0), max(otherChain.max), firstP(NULL), lastP(NULL){
		// counter for index
		unsigned i = 0;
		// push otherChain onto this one
		while(size < otherChain.size)
			pushback(otherChain[i++]);}
	template<class T>
	chain<T>::~chain() {
		while(!empty())
			popBack();}
	template<class T>
	const T &chain<T>::pushBack(const T &newVal)const{
		//set overflow conditions
		if(full())
			throw newVal;
		// Attach to end of list
		if(size == 0)
			firstP = lastP = new node<T>(newVal);
		else{
			lastP->right = new node<T>(newVal);
			lastP->rightP->leftP = lastP;
			lastP = lastP->rightP;}
		// Increment size
		size++;
		return newVal;}
	template<class T>
	const T &chain<T>::pushFront(const T &newVal)const{
		//set overflow conditions
		if(full())
			throw newVal;
		if(empty())
			firstP = lastP = new node<T>(newVal);
		else{
			lastP->leftP = new node<T>(newVal);
			lastP->leftP->rightP = lastP;
			lastP = lastP->leftP;}
		// Increment size
		size++;
		return newVal;}
	template<class T>
	const T &chain<T>::peekFront()const{
		return firstP->val;}
	template<class T>
	const T &chain<T>::peekBack()const{
		return lastP->val;}
	template<class T>
	T chain<T>::popFront() {
		T temp;	//temporary memory for pop
		if(!empty()){
			// detach front node
			node<T> *tempNode = firstP;
			firstP = firstP->rightP;
			// assign value in node to temp
			temp = *(tempNode->val);
			// destroy node
			delete tempNode;
			//decrement size
			size--;}
		// return temp
		return temp;}
	template<class T>
	T chain<T>::popBack() {
		T temp;	//temporary memory for pop
		if(!empty()){
			// detach front node
			node<T> *tempNode = lastP;
			lastP = lastP->rightP;
			// assign value in node to temp
			temp = *(tempNode->val);
			// destroy node
			delete tempNode;
			//decrement size
			size--;}
		// return temp
		return temp;}
	template<class T>
	const unsigned chain<T>::Size()const{
		return size;}
	template<class T>
	const unsigned chain<T>::Max()const{
		return max;}
	template<class T>
	bool chain<T>::full()const{
		return max > 0 && size == max;}
	template<class T>
	bool chain<T>::empty()const{
		return size == 0;}
	// Array index operator
	template<class T>
	T &chain<T>::operator[](unsigned n) {
		int index = 0;
		// check if in range
		if(n >= size)
			throw n;//new out_of_range("");
		// check if lower or higher half of chain
		if(n < (size/2)){
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
			index = size - 1;
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
