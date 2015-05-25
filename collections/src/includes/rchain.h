/*
 * TODO: Utilize inheritance within lists
 * TODO impliment the linked list recursively
 */
#ifndef RCHAIN_H_
#define RCHAIN_H_
#include"basic_chain.cpp"
namespace sktech{
	template<class T>
	class rchain : public basic_chain {
	public:
		rchain();
		rchain(unsigned new_size);
		rchain(unsigned new_size, ...);
		rchain(const rchain<T> &otherChain);
		virtual ~rchain();
		void clear();
		rchain<T> &operator=(const rchain<T> &otherChain)
		T &operator[](unsigned long n);
	private:
		bool grow(unsigned _size, const rchain<T> &otherChain = NULL,
				unsigned long int index = 0);
		T &left(node<T> *nextNode, unsigned long int i,
				unsigned long int index);
		T &right(node<T> *nextNode, unsigned long int i,
				unsigned long int index);
		bool varAdd(va_list &newChain, unsigned long int new_size,
				unsigned long int index = 0);
	};
}
