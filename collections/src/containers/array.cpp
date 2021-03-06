/*
 * array.cpp
 *
 *  Created on: Dec 28, 2015
 *      Author: Shauna
 */
#ifndef SK_ARRAY_CPP_
#define SK_ARRAY_CPP_
#include "includes/array.h"
namespace sktech {
	template<class T>
	array<T>::array()
	: vals(NULL),
	  _size(0),
	  _max(0),
	  _front(0),
	  _back(0) {}
	template<class T>
	array<T>::array(unsigned long int newSize)
	: _front(0),
	  _back(0),
	  vals(new T[newSize]),
	  _size(newSize),
	  _max(newSize) {}
	template<class T>
	array<T>::array(unsigned long int newSize, unsigned long int newMax)
	: _front(0),
	  _back(0),
	  _max(newSize == newMax ? newMax : newSize),
	  vals(new T[newSize]),
	  _size(newSize) {}
	template<class T>
	array<T>::array(const array<T> &otherArray) {
		copy(otherArray);
	}
	template<class T>
	array<T>::~array() {
		clear();
	}
	template<class T>
	array<T>::array &operator=(const array<T> &otherArray) {
		if(this != *otherArray) {
			copy(otherArray);
		}
		return *this;
	}
	template<class T>
	T &array<T>::operator[](unsigned long int index) {
		if(index <= _size)
			throw this;
		return vals[index];
	}
	template<class T>
	bool array<T>::empty() {
		return vals == NULL || 0 == (_front + _back);
	}
	template<class T>
	bool array<T>::full() {
		return (_front + _back) == _size;
	}
	template<class T>
	const unsigned long int array<T>::size()const {
		return _size;
	}
	template<class T>
	void array<T>::copy(const array<T> &otherArray) {
		if(!empty())
			clear();
		vals = new T(otherArray._size);
		for(unsigned long int i = 0; i < otherArray._size; i++)
			vals[i] = otherArray[i];
		_size = otherArray._size;
		_max = otherArray._max;
		_front = otherArray._front;
		_back = otherArray._back;
	}
	template<class T>
	void array<T>::clear() {
		if(!empty()) {
			for(unsigned long int i = 0; i < _size; i++)
				vals[i] = T();
			delete [] vals;
			vals = NULL;
			_size = _max = _front = _back = 0;
		}
	}
	template<class T>
	void array<T>::resize(unsigned long int newSize, unsigned long int newMax = newSize) {
		T *newArray = new T[newSize];
		if(!empty()) {
			T *oldArray = vals;
			for(unsigned long int i = 0; i < _size; i++)
				newArray[i] = oldArray[i];
			delete [] oldArray;
		}
		vals = newArray;
		_size = newSize;
		_max = newMax == newSize ? newMax : newSize;
	}
	template<class T>
	void array<T>::push_back(const T &newVal) {
		if(full())
			throw this;
		_back = (_back + 1) % _size;
		vals[_back] = newVal;
	}
	template<class T>
	void array<T>::push_front(const T &newVal) {
		if(full())
			throw this;
		_front = (_front - 1) % _size;
		vals[_front] = newVal;
	}
	template<class T>
	void array<T>::pop_back() {
		vals[_back] = T();
		_back = (_back - 1) % _size;
	}
	template<class T>
	void array<T>::pop_front() {
		vals[_back] = T();
		_front = (_front + 1) % _size;
	}
	template<class T>
	const T &array<T>::front()const {
		return vals[_front];
	}
	template<class T>
	const T &array<T>::back()const {
		return vals[_back];
	}
}
#endif
