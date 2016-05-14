/*
 * node.h
 *
 *  Created on: Feb 11, 2015
 *      Author: shauna
 */
#ifndef NODE_H_
#define NODE_H_
#ifndef NULL
#define NULL 0
#endif
#ifndef true
#define true 0b1
#endif
#ifndef false
#define false 0b0
#endif
namespace sktech{
	template<class T>
	struct node {
		node();
		node(const node<T> &otherNode);
		node(const T &newVal);
		node(T *newVal);
		virtual ~node();
		virtual node<T> & operator =(const node<T> &otherNode);
		virtual node *leftP, *rightP;
		virtual T *val;
	};
}
#endif /* NODE_H_ */
