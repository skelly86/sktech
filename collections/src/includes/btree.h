/*
 * btree.h
 *
 *  Created on: Dec 24, 2015
 *      Author: Shauna
 */

#ifndef BTREE_H_
#define BTREE_H_
#include"abstracts/basic_tree.cpp"
namespace sktech {
	template<class T, class K = unsigned int>
	class btree : public basic_tree<T,K> {
	public:
		btree();
		btree(const T &value, const K &newKey);
		btree(const btree &otherTree);
		~btree();
		void clear();
		void insert(const T &newVal, const K &newKey);
		const T &search(const K &searchKey);
	private:
		void copy(const branch &oldBranch, branch *newBranch);
		branch climb(const branch *nextBranch, const K &_key);
		void add(const branch *nextBranch, K newKey, T value);
		void purge(branch *nextBranch);
	};
}
#endif /* SRC_INCLUDES_BTREE_H_ */
