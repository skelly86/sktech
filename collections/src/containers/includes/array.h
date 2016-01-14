/*
 * array.h
 *
 *  Created on: Dec 28, 2015
 *      Author: Shauna
 */
#ifndef NULL
#define NULL 0
#endif
#ifndef SK_ARRAY_H_
#define SK_ARRAY_H_
#include<cstdarg>
namespace sktech {
	template<class T>
	class array {
	public:
		array();
		array(unsigned int newSize);
		array(const array &otherArray);
		~array();
		array &operator=(const array &otherArray);
		T &operator[](unsigned long int index);
		bool empty();
		bool full();
		const unsigned long int size()const;
		void copy(const array &otherArray);
		void clear();
		void resize(unsigned long int newSize);
		void push_back(const T &newVal);
		void push_front(const T &newVal);
		void pop_back();
		void pop_front();
		const T &front()const;
		const T &back()const;
	private:
		T *vals;
		//TODO: set up _max variable in structure
		unsigned long int _size, _front, _back;
	};
}
#endif /* SK_ARRAY_H_ */
