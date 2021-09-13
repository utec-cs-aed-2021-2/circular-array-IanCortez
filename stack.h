#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {
public:
	StackArray();
	StackArray(int _capacity);
	void push(T data);
	T pop();
	void display();
	void push_front(T data);
	T pop_front();
};


template <typename T>
StackArray<T>::StackArray(): CircularArray<T>() {};

template <typename T>
StackArray<T>::StackArray(int _capacity): CircularArray<T>(_capacity) {};


// Adding elements operations
template <typename T>
void StackArray<T>::push_front(T data){
	push(data);
}

template <typename T>
void StackArray<T>::push(T data){
	if(front == -1){
		front = 0;
	} else {
		front = next(front);
	}
	array[front] = data;
}


// Removing elements operations
template <typename T>
T StackArray<T>::pop_front(){
	return pop();
}

template <typename T>
T StackArray<T>::pop(){
	T temp = array[front];
	if(front == 0){
		front = -1;
	} else {
		front = prev(front);
	}
	return temp;
}