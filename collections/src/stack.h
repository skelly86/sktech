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
		stack()
			:values(NULL){}
		stack(unsigned long int size)
			:values(new C(size)){}
		stack(unsigned long int size, unsigned long int max)
			:values(new C(size, max)){}
		stack(const stack &otherStack)
			:values(NULL){copy(otherStack);}
		~stack()
			{delete values;}
		stack &operator=(const stack &otherStack)
			{if(this != *otherStack)copy(otherStack);return *this;}
		const unsigned long int size()const
			{return values->size();}
		const unsigned long int max()const
			{return values->max;}
		void copy(const stack &otherStack)
			{if(values != NULL)delete values;
			values = new C(otherStack);}
		void resize(unsigned long int size)
			{values->resize(size);}
		void push(const T &newTop)
			{values->push_back(newTop);}
		void pop()
			{values->pop_back();}
		const T &top()const
			{return values->back();}
	private:
		C *values;
	};
}
#endif /* SRC_STACK_H_ */
