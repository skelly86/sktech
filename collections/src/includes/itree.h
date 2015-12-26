/*
 * itree.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Shauna
 */

#ifndef ITREE_H_
#define ITREE_H_
#include"abstracts/basic_tree.cpp"
namespace sktech {
	template<class T, class K = unsigned int>
	class itree : public basic_tree<T,K> {
	public:
		itree();
		itree(const T &value, const T &newKey);
		itree(const itree &otherTree);
		~itree();
		itree &operator=(const itree &otherTree);
		void clear();
		void insert(const T &newVal, const K &newKey);
		const T &search(const K &searchKey);
	private:
	};
}
#endif /* ITREE_H_ */
