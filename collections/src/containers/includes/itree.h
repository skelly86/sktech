/*
 * itree.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Shauna
 *      Description:	Binary search tree with an iterated search algorithm
 */
#ifndef ITREE_H_
#define ITREE_H_
#include"abstracts/basic_tree.cpp"
namespace sktech {
	template<class T, class K = unsigned long int>
	class itree : public basic_tree<T,K> {
	public:
		itree();
		itree(const T &value, const K &newKey);
		itree(const itree &otherTree);
		~itree();
		basic_tree<T,K> &operator=(const basic_tree<T,K> &otherTree);
		const T &search(const K &searchKey);
	private:
		branch<T,K> &climb(const K &_key);
	};
}
#endif /* ITREE_H_ */
