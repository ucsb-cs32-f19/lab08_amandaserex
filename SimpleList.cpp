#include <iostream>
#include "SimpleList.h"

template <class T>
SimpleList<T>::SimpleList(){
	numElements=0;
	elements = new  a[CAPACITY];
	for(int i=0;i<CAPACITY;i++){
		elements[i]=NULL;
	}
}
void destroy(T* t){
	delete t;
}

template <class T>
SimpleList<T>::~SimpleList(){
	if(is_pointer<T>::value){
		destroy(element[i]);
	}

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
	return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
	int h = getNumElements();
	if(h==CAPACITY){
		throw FullListException();
	}
	numElements=numElements+1;
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
	numElements=numElements-1;
	return;
}

