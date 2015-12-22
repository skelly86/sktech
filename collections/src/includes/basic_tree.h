/*
 * basic_tree.h
 *
 *  Created on: Dec 19, 2015
 *      Author: Shauna
 *      TODO: implement the abstract class
 */

#ifndef BASIC_TREE_H_
#define BASIC_TREE_H_
#include"node.cpp"
namespace sktech {
	template<class T, class K = unsigned int>
	class basic_tree {
	public:
		virtual basic_tree();
		virtual basic_tree(const basic_tree &otherTree) = 0;
		virtual ~basic_tree() = 0;
		const unsigned int size() const;
		virtual void insert(const T & newVal) = 0;
		virtual const T &search(const K &searchKey) = 0;
	protected:
		typedef struct branch<T,K> : public node<T> {
			branch();
			branch(const branch &otherBranch);
			branch &operator=(const branch &otherBranch);
			K *key;
		};
		node<T> *root;
		unsigned int _size;
	private:
	};
}
#endif /* BASIC_TREE_H_ */
