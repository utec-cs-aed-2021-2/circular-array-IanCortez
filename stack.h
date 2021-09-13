#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {
public:
	StackArray();
	StackArray(int _capacity);
	void push(T data);
	T pop();
	void display();
};


template <typename T>
StackArray<T>::StackArray(): CircularArray<T>() {};

template <typename T>
StackArray<T>::StackArray(int _capacity): CircularArray<T>(_capacity) {};

template <typename T>
void StackArray<T>::push(T data){
	if(front == -1){
		front = 0;
	} else {
		front = next(front);
	}
	array[front] = data;
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