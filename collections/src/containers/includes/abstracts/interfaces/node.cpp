/*
 * @author: Shauna Kelly
 */
#ifndef NODE_CPP_
#define NODE_CPP_
#include"node.h"
namespace sktech{
	template<class T>
	node<T>::node():leftP(NULL), rightP(NULL), val(NULL){}
	template<class T>
	node<T>::node(const node<T> &otherNode)
	:leftP(NULL), rightP(NULL), val(new T(otherNode->val)){}
	template<class T>
	node<T>::node(const T &newVal)
	: leftP(NULL), rightP(NULL), val(new T(newVal)){}
	template<class T>
	node<T>::node(T *newVal)
	: leftP(NULL), rightP(NULL), val(newVal){}
	template<class T>
	node<T>::~node(){
		*val = T();
		delete val;
		val = leftP = rightP = NULL;
	}
	template<class T>
	node<T> & node<T>::operator =(const node<T> &otherNode){
		if(this != *otherNode){
			delete val;
			val = new T(otherNode->val);
		}
		return *this;
	}
}
#endif
