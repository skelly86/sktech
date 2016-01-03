/*
 * basic_chain.h
 *
 *  Created on: May 20, 2015
 *      Author: shauna
 *      description: abstract class for chain and rchain
 */

#ifndef BASIC_CHAIN_H_
#define BASIC_CHAIN_H_
#include"node.cpp"
#include<cstdarg>
namespace sktech {
	template<class T>
	class basic_chain {
	public:
		virtual basic_chain();
		virtual basic_chain(const basic_chain &otherChain) = 0;
		virtual ~basic_chain() = 0;
		virtual basic_chain operator=(const basic_chain &otherChain) = 0;
		virtual T &operator[](unsigned long int n) = 0;
		virtual void clear() = 0;
		virtual void copy(const basic_chain &otherChain) = 0;
		virtual void push_back(const T &newVal)const;
		virtual void push_front(const T &newVal)const;
		virtual const T &front()const;
		virtual const T &back()const;
		virtual void pop_front();
		virtual void pop_back();
		virtual const unsigned long int size()const;
		virtual const unsigned long int max()const;
		virtual bool full()const;
		virtual bool empty()const;
	protected:
		virtual void add(node<T> *addPoint, const T &newVal, bool first);
		virtual void remove(node<T> *deletePoint, bool first);
		virtual unsigned long int _size, _max;
		virtual node<T> *firstP;
		virtual node<T> *lastP;
	private:
	};
}
#endif /* BASIC_CHAIN_H_ */
