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
namespace sktech{
	template<class T>
	struct node{
		virtual node();
		virtual node(const node<T> &otherNode);
		virtual node(const T &newVal);
		virtual node(T *newVal);
		virtual ~node();
		virtual node<T> & operator =(const node<T> &otherNode);
		virtual node *leftP, *rightP;
		virtual T *val;
	};
}
#endif /* NODE_H_ */
