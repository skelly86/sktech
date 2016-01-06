/*
 * basic_tree.h
 *
 *  Created on: Dec 19, 2015
 *      Author: Shauna
 *      TODO: Because the difference between derived classes is search(K),
 *      	move other functions to abstract class to remove redundant code.
 */
#ifndef BASIC_TREE_H_
#define BASIC_TREE_H_
#include"node.cpp"
namespace sktech {
	template<class T, class K = unsigned long int>
	class basic_tree {
	public:
		virtual basic_tree();
		virtual basic_tree(const basic_tree &otherTree);
		virtual basic_tree(const T &value, const K &newKey);
		virtual ~basic_tree();
		virtual basic_tree &operator=(const basic_tree &otherTree);
		virtual void clear();
		virtual const unsigned int size() const;
		virtual void insert(const T &newVal, const K &newKey);
		virtual const T &search(const K &searchKey) = 0;
	protected:
		virtual struct branch : public node<T> {
			branch();
			branch(const T &newVal, const K &newKey);
			branch(const branch &otherBranch);
			~branch();
			branch &operator=(const branch &otherBranch);
			bool operator==(const branch &otherBranch);
			bool operator!=(const branch &otherBranch);
			bool operator<(const branch &otherBranch);
			bool operator>(const branch &otherBranch);
			K key;
		};
		virtual node<T> *root;
	private:
		virtual void copy(branch *oldBranch, branch *newBranch);
		virtual void add(branch *&nextBranch, const K &newKey, const T &value);
		virtual void purge(branch *nextBranch);
		virtual unsigned long int _size;
	};
}
#endif /* BASIC_TREE_H_ */
