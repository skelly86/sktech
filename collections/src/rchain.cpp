/*
 *
 */
#ifndef RCHAIN_CPP_
#define RCHAIN_CPP_
#include"includes/rchain.h"
namespace sktech{
	template<class T>
	rchain<T>::rchain()
	:max(0), _size(0), firstP(NULL), lastP(NULL){}
	template<class T>
	rchain<T>::rchain(unsigned new_size):max(0),_size(0){
		grow(new_size);}
	template<class T>
	rchain<T>::rchain(unsigned new_size, ...)
	:_size(0), max(0), firstP(NULL), lastP(NULL){
		va_list newChain;
		va_start(newChain, new_size);
		varAdd(newChain, new_size);
		va_end(newChain);}
	template<class T>
	rchain<T>::rchain(const rchain<T> &otherChain)
	:max(0), _size(0){
		grow(otherChain._size, otherChain);}
	template<class T>
	rchain<T>::~rchain(){
		clear();}
	template<class T>
	void rchain<T>::clear(){
		if(empty())
			max = 0;
		else{
			pop_front();
			clear();}}
	template<class T>
	void rchain<T>::push_back(const T &newVal)const{
		if(!full())
			add(lastP, newVal, false);}
	template<class T>
	void rchain<T>::push_front(const T &newVal)const{
		if(!full())
			add(firstP, newVal, true);}
	template<class T>
	const T &rchain<T>::front()const{
		return firstP->val;}
	template<class T>
	const T &rchain<T>::back()const{
		return lastP->val;}
	template<class T>
	void rchain<T>::pop_front(){
		remove(firstP, true);)}
	template<class T>
	void rchain<T>::pop_back(){
		remove(lastP, false);}
	template<class T>
	const size_t rchain<T>::size()const{
		return _size;}
	template<class T>
	const size_t rchain<T>::Max()const{
		return max;}
	template<class T>
	bool rchain<T>::full()const{
		return max > 0 && max == _size;}
	template<class T>
	bool rchain<T>::empty()const{
		return _size == 0;}
	template<class T>
	rchain<T> &rchain<T>::operator=(const rchain<T> &otherChain){
		//TODO Implement this operator
		if(this != *otherChain){
			clear();
			grow(otherChain._size, otherChain);}
		return *this;}
	template<class T>
	T &rchain<T>::operator[](unsigned n){
		if(n > _size)
			throw n;
		if(n > _size/2)
			return left(lastP, _size-1, n);
		return right(firstP, 0, n);}
	template<class T>
	bool rchain<T>::grow(unsigned _size, const rchain<T> &otherChain = NULL, unsigned index = 0){
		//Only used for initialization and assignment
		if(!empty())
			return false;
		if(index + 1 == _size){
			if(&otherChain == NULL)
				push_back(new T());
			else
				push_back(otherChain[index]);
			return grow(_size, otherChain, index++);}
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
	bool rchain<T>::varAdd(va_list &newChain, unsigned new_size, unsigned index = 0){
		if(index == new_size)
			return true;
		push_back(va_arg(newChain,T));
		return varAdd(newChain, new_size, index+1);}
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
