//---------------------------------------------------------------------
// Name: Kishan Patel
// Email: kpp5282@psu.edu
// Class: CMPSC 122, Section 2
// Program 2
// Due Date: February 28, 2018, 11:59 PM
//
// Description: This program implements a basic integer vector
// and provides the user with an interactive prompting system
// to issue commands over an instance of our BasicVector class.
//
// Acknowledgements:
// 1. Please use this portion of the banner comment to list
// any resources or individuals you consulted on the creation
// of this program.sint
//---------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//Implement the Class
template <class T>
class BasicVector
{
	
private:
	
	//Number of Items in data
	int vector_size;
	
	//Maximum number of items that can be contained in data before it needs to be resized
	int vector_capacity;
	
	//Pointer that points to a dynamically allocated array
	int* data;

	void resize(int, int);

public:
	
	// default constructor does nothing
	BasicVector() {};
	
	
	BasicVector(int);
	
	
	~BasicVector();


	int& at(int);
	int& operator[](int);
	int& front();
	int& back();
	
	void expand();
	void expand(int);
	void push_back(int);
	void insert(int, int);
	void pop_back();
	//Check this
	void reserve(int);
	
	bool empty();
	int size();
	int capacity();

	void print();
};

template <class T>
void BasicVector<T>::reserve(int newCapacity)
{
	vector_capacity = newCapacity;
	int* newArr = new int[vector_capacity];
	for (int i = 0; i < vector_size; ++i) newArr[i] = data[i];
	delete [] data;
	data = newArr;
}

template <class T>
void BasicVector<T>::resize(int size, int value)
{
	 if (size < vector_size) {
		vector_size = size;
}
	if (vector_capacity < size) {
		expand(size - vector_capacity);
}
	if (size > vector_capacity) {
		expand();
}
	int* ptr = data;
	data = new int[size];
	for (int j = 0; j < vector_size; ++j) {
		data[j] = ptr[j];
}
	for (int k = vector_size; k < size; ++k) {
		data[k] = value;
}
	vector_size = size;
	delete[] ptr;
	return;
}

template <class T>
BasicVector<T>::BasicVector(int)
{
	vector_size = 0;
	vector_capacity = 0;
	data = 0;
}

template <class T>
BasicVector<T>::~BasicVector()
{	
	delete [] data;
}

template <class T>
int& BasicVector<T>::at(int index)
{
	return data[index];
}

template <class T>
int& BasicVector<T>::operator[](int index)
{
	return data[index];
}

template <class T>
int& BasicVector<T>::front()
{
	return data[0];
}

template <class T>
int& BasicVector<T>::back()
{
	return data[vector_size-1];
}

template <class T>
void BasicVector<T>::push_back(int item)
{
	++vector_size;
	if(vector_size>= vector_capacity){
		expand();
}
	data[vector_size-1] = item;
}
	
template <class T>
void BasicVector<T>::insert(int index, int value)
{
	++vector_size;
	if(vector_size > vector_capacity){
		expand(vector_size-vector_capacity);
}
	if (vector_size >= vector_capacity){
		expand();
}
	if(index >= vector_size ){
		throw out_of_range("BasicVector::insert_range_check");
}	  
	int *ptr = data;
	data = new int[vector_capacity];	  
	for(int i = 0; i < index;++i){
		data[i] = ptr[i];
}
	data[index] = value;	  
	for(int i = index; i < vector_size; ++i){
		data[i + 1] = ptr[i];
}
	for(int i= vector_size; i < vector_capacity; ++i){
		data[i] = 0;
}
	delete[] ptr;
	return;	
}

template <class T>
void BasicVector<T>::pop_back()
{
	--vector_size;
}

template <class T>
int BasicVector<T>::size()
{
	return vector_size;
}

template <class T>
int BasicVector<T>::capacity()
{
	return vector_capacity;
}

template <class T>
void BasicVector<T>::print()
{

		cout << "elements" << vector_size << " " << data << endl;
}

template <class T>
void BasicVector<T>::expand()

{
	if(vector_capacity == 0)
		expand(1);
	else
		expand(vector_capacity);
}

template <class T>
void BasicVector<T>::expand(int amount)
{
	vector_capacity += amount;
	int *temp = new int[vector_capacity];
		for(int i = 0; i < vector_size; i++)
			temp[i] = data[i];
		if(data != nullptr)
			delete []data;
				data = temp;
}

template <class T>
bool BasicVector<T>::empty()
{
	if(vector_size == 0){
		return true;
}
	else{
	return false;
}
}

#include <vector>
int main()
{
	cout << "Specify what data type to store in vector:" << endl;
	cout << "1) int" << endl;
	cout << "2) float" << endl;
	cout << "3) double" << endl;
	cout << "4) string" << endl;
	cout << "5) bool" << endl;
	int choice ;
	cin >> choice;
	int capacity;
	cout << "Enter starting capacity of vector: ";
	cin >> capacity;


	//BasicVector v1(capacity);


	//while(i < v1)
	//{
	//v1.at(i) = i;
	//}
	

	return 0;
}