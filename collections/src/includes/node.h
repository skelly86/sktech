/*
 * node.h
 *
 *  Created on: Feb 11, 2015
 *      Author: shauna
 */
#ifndef NULL
#define NULL 0
#endif
#ifndef NODE_H_
#define NODE_H_
#include<cstdarg>
namespace sktech{
	template<class T>
	struct node{
		virtual node():leftP(NULL), rightP(NULL), val(NULL){};
		virtual node(const node<T> &otherNode)
				:leftP(NULL), rightP(NULL), val(new T(otherNode->val)){};
		virtual node(const T &newVal): leftP(NULL), rightP(NULL), val(new T(newVal)){};
		virtual node(T *newVal): leftP(NULL), rightP(NULL), val(newVal){};
		virtual ~node(){leftP = rightP = NULL; delete val;};
		virtual node *leftP, *rightP;
		virtual T *val;
	};
}
#endif /* NODE_H_ */
