/*
 * itree.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Shauna
 */

#ifndef SRC_INCLUDES_ITREE_H_
#define SRC_INCLUDES_ITREE_H_
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
	private:
	};
}
#endif /* SRC_INCLUDES_ITREE_H_ */
