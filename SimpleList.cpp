#include <iostream>
#include "SimpleList.h"

template <class T>
SimpleList<T>::SimpleList(){
	T a[CAPACITY];
	a=NULL;
	elements = a;
}

template <class T>
SimpleList<T>::~SimpleList(){
	delete elements;
}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){
	if(elements[index]==NULL){
		throw InvalidIndexException();
	}
	return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const{
	if(elements==NULL){
		return true;
	}
	return false;
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException){
	if(empty()){
		throw EmptyListException();
	}
	return elements[0];
}


template <class T>
T SimpleList<T>::last() const throw (EmptyListException){
	if(empty()){
		throw EmptyListException();
	}
	for(int i=CAPACITY-1; i>=0;i--){
		if(elements[i]!=NULL){
			return elements[i];
		}
	}
}

template <class T>
int SimpleList<T>::getNumElements() const{
	//stub
	return 0;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
	//stub
	return;
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
	//stub
	return;
}

