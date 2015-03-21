/*
 *
 */
#ifndef RCHAIN_CPP_
#define RCHAIN_CPP_
#include"includes/rchain.h"
namespace sktech{
	template<class T>
	rchain<T>::rchain()
	:max(0), size(0), firstP(NULL), lastP(NULL){}
	template<class T>
	rchain<T>::rchain(unsigned newSize):max(0),size(0){
		grow(newSize);}
	template<class T>
	rchain<T>::rchain(unsigned newSize, ...)
	:size(0), max(0), firstP(NULL), lastP(NULL){
		va_list newChain;
		va_start(newChain, newSize);
		varAdd(newChain, newSize);
		va_end(newChain);}
	template<class T>
	rchain<T>::rchain(const rchain<T> &otherChain)
	:max(0), size(0){
		grow(otherChain.size, otherChain);}
	template<class T>
	rchain<T>::~rchain(){
		clear();}
	template<class T>
	void rchain<T>::clear(){
		if(!empty()){
			popFront();
			clear();}}
	template<class T>
	const T &rchain<T>::pushBack(const T &newVal)const{
		T temp = empty() ? T() : *(lastP->val);
		remove(lastP, false);
		if(empty())
			firstP = lastP = NULL;
		return temp;}
	template<class T>
	const T &rchain<T>::pushFront(const T &newVal)const{
		T temp = empty() ? T() : *(firstP->val);
		remove(firstP, true);
		if(empty())
			firstP = lastP = NULL;
		return temp;}
	template<class T>
	const T &rchain<T>::peekFront()const{
		return firstP->val;}
	template<class T>
	const T &rchain<T>::peekBack()const{
		return lastP->val;}
	template<class T>
	T rchain<T>::popFront();
	template<class T>
	T rchain<T>::popBack();
	template<class T>
	const size_t rchain<T>::Size()const{
		return size;}
	template<class T>
	const size_t rchain<T>::Max()const{
		return max;}
	template<class T>
	bool rchain<T>::full()const{
		return max > 0 && max == size;}
	template<class T>
	bool rchain<T>::empty()const{
		return size == 0;}
	template<class T>
	rchain<T> &rchain<T>::operator=(const rchain<T> &otherChain){
		if(this != *otherChain){
		}
		return this;}
	template<class T>
	T &rchain<T>::operator[](unsigned n){
		if(n > size)
			throw n;
		if(n > size/2)
			return left(lastP, size-1, n);
		return right(firstP, 0, n);}
	template<class T>
	bool rchain<T>::grow(unsigned size, const rchain<T> &otherChain = NULL, unsigned index = 0){
		//Only used for initialization and assignment
		if(!empty())
			return false;
		if(index + 1 == size){
			if(&otherChain == NULL)
				pushBack(new T());
			else
				pushBack(otherChain[index]);
			return grow(size, otherChain, index++);}
		return true;
	}
	template<class T>
	T &rchain<T>::left(node<T> *nextNode, unsigned i, unsigned index){
		if(i == index)
			return *(nextNode->val);
		return left(nextNode->leftP, i-1, index);}
	template<class T>
	T &rchain<T>::right(node<T> *nextNode, unsigned i, unsigned index){
		if(i == index)
			return *(nextNode->val);
		return right(nextNode->rightP, i+1, index);}
	template<class T>
	bool rchain<T>::add(node<T> *addPoint, const T &newVal, bool first){
		if(full())
			return false;
		node<T> *newNode = new node<T>(newVal);
		if(empty())
			firstP = lastP = newNode;
		else{
			if(first)
				firstP = firstP->leftP = newNode;
			else
				lastP = lastP->rightP = newNode;}
		return true;}
	template<class T>
	bool rchain<T>::varAdd(va_list &newChain, unsigned newSize, unsigned index = 0){
		if(index == newSize)
			return true;
		pushBack(va_arg(newChain,T));
		return varAdd(newChain, newSize, index+1);}
	template<class T>
	bool rchain<T>::remove(node<T> *deletePoint, bool first){
		if(empty())
			return false;
		if(first){
			firstP = firstP->rightP;
			delete firstP->leftP;}
		else{
			lastP = lastP->leftP;
			delete lastP->rightP;}}
		return true;}
}
