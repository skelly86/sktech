/*
 * lineartree.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: shauna
 */
#ifndef RECURSIVE_STACK_CPP_
#define RECURSIVE_STACK_CPP_
#include "includes/recursivestack.h"
namespace sktech{
	template<class T>
	recursive_stack<T>::recursive_stack()
	:root(NULL), size(0), max(0){}
	template<class T>
	recursive_stack<T>::recursive_stack(unsigned newMax)
	:root(NULL), size(0), max(newMax){}
	template<class T>
	recursive_stack<T>::recursive_stack(const recursive_stack<T> &otherStack)
	:root(NULL), size(0), max(0){
		unsigned i = otherStack.size - 1;
		max = otherStack.max;
		while(size < otherStack.size)
			push(otherStack[i--]);
	}
	template<class T>
	recursive_stack<T>::~recursive_stack(){
		pop();
		if(!empty())
			~recursive_stack();}
	template<class T>
	T &recursive_stack<T>::push(const T &newVal){
		if(!down(root, newVal))
			throw this;
	}
	template<class T>
	T recursive_stack<T>::pop(){
	}
	template<class T>
	bool recursive_stack<T>::full()const{
		return size == max && max > 0;
	}
	template<class T>
	bool recursive_stack<T>::empty()const{
		return size == 0;
	}
	template<class T>
	recursive_stack<T> &recursive_stack<T>::operator=(const recursive_stack<T> &otherStack){
		if(*otherStack != this){
			unsigned i = otherStack.size - 1;
			max = otherStack.max;
			while(size < otherStack.size)
				push(otherStack[i--]);}
		return *this;}
	template<class T>
	T &recursive_stack<T>::operator[](unsigned n){
		int i = 0;
		return down(root, n, i);}
	template<class T>
	bool recursive_stack<T>::down(node<T> *child, T *nextVal){
		//overflow condition
		if(full())
			return false;
		// temp pointer to value to move down
		T *tempP = child->val;
		if(child->val == NULL){
			child->val = nextVal;
			return true;
		}
		child->val = nextVal;
		if(child->rightP == NULL){
			child->rightP = new node<T>(tempP);
			return true;}
	}
	template<class T>
	T &recursive_stack<T>::down(node<T> *child, unsigned index, unsigned i){
		//TODO
		if(i == index)
			return child->val;
		return down(child->rightP, index, i+1);}
	template<class T>
	T *recursive_stack<T>::up(node<T> *child){
		//TODO
		T * temp = child->val;
		if(child->rightP != NULL)
			child->val = up(child->rightP);
		else{
			child->val = NULL;
			delete child;}
		return temp;
	}
}
#endif // RECURSIVE_STACK_CPP_
