#include <iostream>
using namespace std;


template <class T>
class CircularArray {
protected:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

protected:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray(){
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity){
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray(){
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index){
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index){
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep){
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}


template <typename T>
void CircularArray<T>::push_front(T data){
    if(front == -1 && back == -1){
        front = back = 0;
    } else {
        front = prev(front);
    }
    array[front] = data;
}


template <typename T>
void CircularArray<T>::push_back(T data){
    if(front == -1 && back == -1){
        front = back = 0;
    } else {
        back = next(back);
    }
    array[back] = data;
}


template <typename T>
void CircularArray<T>::insert(T data, int pos){
    array[front + pos] = data;
}


template <typename T>
T CircularArray<T>::pop_front(){
    T temp = array[front];
    if(front == back){
        front = back = -1;
    } else {
        front = next(front);
    }
    return temp;
}


template <typename T>
T CircularArray<T>::pop_back(){
    T temp = array[back];
    if(front == back){
        front = back = -1;
    } else {
        back = prev(back);
    }

    return temp;
}


template <typename T>
bool CircularArray<T>::is_full(){
    return (next(back) == front);
}


template <typename T>
bool CircularArray<T>::is_empty(){
    return (front == -1);
}


template <typename T>
int CircularArray<T>::size(){
    auto temp = front;
    int counter = 0;
    while(temp != back){
        temp = next(temp);
        ++counter;
    }
    return (counter + 1);
}


template <typename T>
void CircularArray<T>::clear(){
    while(next(front) != back){
        array[front] = 0;
        front = next(front);
    }
    array[front] = 0;
    front = back = -1;
}


template <typename T>
T& CircularArray<T>::operator[](int pos){
    auto temp = front;
    while(pos != 0){
        temp = next(temp);
        --pos;
    }
    return array[temp];
    //return *((array + front) + pos);
}



// Quicksort
void swap_a(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int* arr, int low, int high){
	int pivot = *(arr + high);	// ultimo elemento del vector
	int i = (low - 1);

	for(int j=low; j<=high-1; ++j){
		if(arr[j] < pivot){
			++i;
			swap_a(&arr[i], &arr[j]);
		}
	}

	swap_a(&arr[i+1], &arr[high]);

	return (i+1);
}


void quicksort(int* arr, int low, int high){
	if(low < high){
		int pivot = partition(arr, low, high);	// Generar indice para la particion

		quicksort(arr, low, pivot-1);	// Hacer un quicksort para la parte izquierda del array
		quicksort(arr, pivot+1, high);	// Hacer un quicksort para la parte derecha del array
	}
}


template <typename T>
void CircularArray<T>::sort(){
    quicksort(array, 0, capacity-1);
    front = 0;
    back = capacity-1;
}


template <typename T>
bool CircularArray<T>::is_sorted(){
    if (capacity <= 1) return true;
    for(int i=1; i<size(); ++i){
        if(array[i-1] > array[i]) return false;
    }
    return true;
}


template <typename T>
void CircularArray<T>::reverse(){
    int* temp = new int[capacity];
    for(int i=size()-1; i>=0; --i){
        temp[size()-1 - i] = array[i];
    }
    delete[] array;
    array = temp;
}