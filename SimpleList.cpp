#include <iostream>
#include "SimpleList.h"

template <class T>
SimpleList<T>::SimpleList(){
	T a[CAPACITY];
	for(int i=0;i<CAPACITY;i++){
		a[i]=NULL;
	}
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
	int count=0;
	for(int i=0; i<CAPACITY; i++){
		if(elements[i]==NULL){
			return count;
		}
		count=count+1;
	}
	return count;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
	int h = getNumElements();
	if(h==CAPACITY){
		throw FullListException();
	}
	elements[h]=item;
	return;
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
	if(empty()){
		throw EmptyListException();
	}
	at(index);
	int move=index;
	while(elements[move]!=NULL && move+1<CAPACITY){
		elements[move]=elements[move+1];
		move=move+1;
	}
	if(move+1==CAPACITY){
		elements[move]=NULL;
	}
	return;
}

