/*
 * queue.h
 *
 *  Created on: Jan 14, 2016
 *      Author: Shauna
 */
#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_
#include"containers/array.cpp"
namespace sktech {
	template<class T, class C = array<T>>
	class queue {
	public:
		queue()
			:values(NULL){}
		queue(unsigned long int size)
			:values(new C(size)){}
		queue(unsigned long int size, unsigned long int max)
			:values(new C(size, max)){}
		queue(const queue &otherqueue)
			:values(NULL){copy(otherqueue);}
		~queue()
			{delete values;}
		queue &operator=(const queue &otherqueue);
		T &operator[](unsigned long int n)
			{return *(values[n]);}
		const unsigned long int size()const
			{return values->size();}
		const unsigned long int max()const
			{return values->max();}
		void copy(const queue &otherqueue);
		void resize(unsigned long int size)
			{values->resize(size);}
		void push(const T &newTop)
			{values->push_back(newTop);}
		void pop()
			{values->pop_front();}
		const T &front()const
		{return values->front();}
	private:
		C *values;
	};
	template<class T, class C = array<T>>
	queue<T,C> &queue<T,C>::operator=(const queue &otherqueue) {
		if(this != *otherqueue)
			copy(otherqueue);
		return *this;
	}
	template<class T, class C = array<T>>
	void queue<T,C>::copy(const queue &otherqueue){
		if(values != NULL)
			delete values;
		values = new C(otherqueue);
	}
}
#endif /* SRC_QUEUE_H_ */
