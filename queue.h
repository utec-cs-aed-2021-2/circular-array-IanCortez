#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
public:
	QueueArray();
	QueueArray(int _capacity);
	void enqueue(T data);
	T dequeue();
	void push_back(T data);
	T pop_front();
};


template <typename T>
QueueArray<T>::QueueArray(): CircularArray<T>() {}

template <typename T>
QueueArray<T>::QueueArray(int _capacity): CircularArray<T>(_capacity) {}


template <typename T>
void QueueArray<T>::push_back(T data){
	enqueue(data);
}


template <typename T>
void QueueArray<T>::enqueue(T data){
	if(back == front == -1){
		back = front = 0;
	} else {
		back = next(back);
	}
	array[back] = data;
}


template <typename T>
T QueueArray<T>::pop_front(){
	return dequeue();
}


template <typename T>
T QueueArray<T>::dequeue(){
	T temp = array[front];
	if(front == back){
		front = back = -1;
	} else {
		front = next(front);
	}
	return temp;
}
