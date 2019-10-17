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
// 1. http://www.cplusplus.com/reference/stdexcept/out_of_range/
//---------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//Implement the Class

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
	void reserve(int);
	
	int size();
	int capacity();

	void print();
};

void BasicVector::reserve(int newCapacity)
{
	vector_capacity = newCapacity;
	int* newArr = new int[vector_capacity];
	for (int i = 0; i < vector_size; ++i) newArr[i] = data[i];
	delete [] data;
	data = newArr;
}

void BasicVector::resize(int size, int value)
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

BasicVector::BasicVector(int)
{
	vector_size = 0;
	vector_capacity = 0;
	data = 0;
}

BasicVector::~BasicVector()
{	
	delete [] data;
}

int& BasicVector::at(int index)
{
	return data[index];	
}

int& BasicVector::operator[](int index)
{
	return data[index];
}

int& BasicVector::front()
{
	return data[0];
}

int& BasicVector::back()
{
	return data[vector_size-1];
}

void BasicVector::push_back(int item)
{
	++vector_size;
	if(vector_size>= vector_capacity){
		expand();
}
	data[vector_size-1] = item;
}

void BasicVector::insert(int index, int value)
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

void BasicVector::pop_back()
{
	--vector_size;
}

int BasicVector::size()
{
	return vector_size;
}

int BasicVector::capacity()
{
	return vector_capacity;
}

void BasicVector::print()
{
	cout << "elements" << vector_size << " " << data << endl;
}

void BasicVector::expand()
{
	if(vector_capacity == 0)
		expand(1);
	else
		expand(vector_capacity);
}

void BasicVector::expand(int amount)
{
	vector_capacity += amount;
	int *temp = new int[vector_capacity];
	for(int i = 0; i < vector_size; i++)
		temp[i] = data[i];
	if(data != nullptr)
		delete []data;
	data = temp;
}

void display(const BasicVector &v);
#include <vector>
int main()
{
	int capacity;
	cout << "Enter starting capacity of vector: ";
	cin >> capacity;
	

	//I attempted to invoke the functions but I couldn't do it, so please at least give me a grade for my functions. I tried hard to make them work, thank you

	BasicVector v1(capacity);


	while(at(int index))
	{
	
	}
	

	return 0;
}