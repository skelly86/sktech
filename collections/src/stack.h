/*
 * stack.h
 *
 *  Created on: Jan 12, 2016
 *      Author: Shauna
 */

#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include"containers/array.cpp"
namespace sktech {
	template<class T, class C = array<T>>
	class stack {
	public:
	private:
		C values;
	};
}
#endif /* SRC_STACK_H_ */
