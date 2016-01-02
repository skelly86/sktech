/*
 *
 */
#ifndef BASIC_CHAIN_CPP_
#define BASIC_CHAIN_CPP_
#include"interfaces/basic_chain.h"
namespace sktech {
	template<class T>
	basic_chain<T>::basic_chain()
	:_size(0), _max(0), firstP(NULL), lastP(NULL) {}
	// TODO reimpliment push functions
	template<class T>
	const T &basic_chain<T>::push_back(const T &newVal) const {
		if(!full())
			add(lastP, newVal, false);
		return back();
	}
	template<class T>
	const T &basic_chain<T>::push_front(const T &newVal) const {
		if(!full())
			add(firstP, newVal, true);
		return front();
	}
	template<class T>
	const T &basic_chain<T>::front() const {
		return firstP->val;
	}
	template<class T>
	const T &basic_chain<T>::back() const {
		return lastP->val;
	}
	template<class T>
	T basic_chain<T>::pop_front() {
		T temp = empty() ? T() : front();
		remove(firstP, 0x01);
		return temp;
	}
	template<class T>
	T basic_chain<T>::pop_back() {
		T temp = empty() ? T() : back();
		remove(lastP, 0x00);
		return temp;
	}
	template<class T>
	const unsigned long int basic_chain<T>::size() const {
		return _size;
	}
	template<class T>
	const unsigned long int basic_chain<T>::max() const {
		return _max;
	}
	template<class T>
	bool basic_chain<T>::full() const {
		return _max > 0 && _size == _max;
	}
	template<class T>
	bool basic_chain<T>::empty() const {
		return _size == 0;
	}
	template<class T>
	bool basic_chain<T>::add(node<T> *addPoint, const T &newVal, bool first) {
		if(full())
			return false;
		node<T> *newNode = new node<T>(newVal);
		if(empty())
			firstP = lastP = newNode;
		else {
			if(first)
				firstP = firstP->leftP = newNode;
			else
				lastP = lastP->rightP = newNode;
		}
		return true;
	}
	template<class T>
	bool basic_chain<T>::remove(node<T> *deletePoint, bool first) {
		if(empty())
			return false;
		if(first) {
			firstP = firstP->rightP;
			delete firstP->leftP;
			firstP->leftP = NULL;
		}
		else {
			lastP = lastP->leftP;
			delete lastP->rightP;
			lastP->rightP = NULL;
		}
		return true;
	}
}
#endif /* BASIC_CHAIN_CPP_ */
