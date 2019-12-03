#include <iostream>
#include <type_traits>
#include "SimpleList.h"

template <class T>
SimpleList<T>::SimpleList(){
	numElements=0;
	elements = new  T[CAPACITY];
}

template <class T>
void destroy(T* element){
	delete element;
}
template <class T>
void destroy(T element){
}

template <class T>
SimpleList<T>::~SimpleList(){
		if(std::is_pointer<T>::value){
			for(int i=0; i<numElements; i++){
				destroy(elements[i]);
				}
			delete [] elements;
		}
		else{ 
			delete[] elements;
		}
}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){
	if(index>=numElements || index<0){
		throw InvalidIndexException();
	}
	return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const{
	if(numElements==0){
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
	return elements[numElements-1];
}

template <class T>
int SimpleList<T>::getNumElements() const{
	return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
	if(numElements==CAPACITY){
		throw FullListException();
	}
	elements[numElements]=item;
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
	destroy(elements[index]);
	while(move<numElements){
		elements[move]=elements[move+1];
		move=move+1;
	}
	numElements=numElements-1;
	return;
}

