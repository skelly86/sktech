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
	template<class T, class K = unsigned long int>
	class btree : public basic_tree<T,K> {
	public:
		btree();
		btree(const T &value, const K &newKey);
		btree(const btree &otherTree);
		~btree();
		basic_tree<T,K> &operator=(const basic_tree<T,K> &otherTree);
		const T &search(const K &searchKey);
	private:
		branch &climb(const branch *nextBranch, const K &_key);
	};
}
#endif /* BTREE_H_ */
