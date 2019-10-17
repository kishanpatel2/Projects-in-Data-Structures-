//---------------------------------------------------------------------
// Name: Kishan Patel
// Email: kpp5282@psu.edu
// Class: CMPSC 122, Section 3
// Program 3.2
// Due Date: March 28, 2018, 11:59 PM
//
// Description: Using the list.h file implement the set class
//
//
// Acknowledgements:
//
//---------------------------------------------------------------------

#include <iostream>
#include "list.h"

using namespace std;

class Set
{
private: 
	List* list;
	int set_size;
public:
	Set();
	~Set();
	
	//Still have to do this
	bool contains(int value);
	
	bool add(int value);
	bool remove(int value);
	void clear();

	Set* set_union(Set&);
	Set* intersection(Set&);
	Set* difference(Set&);

	void print();
	int size() { return set_size; }
};

Set::Set()
{
	list = new List();
	set_size = 0;
}

Set::~Set()
{
	clear();
}

//CHECK THIS
bool Set::contains (int value)
{
	return list -> contains(value);
}


bool Set::add (int value)
{
	if(list -> contains(value)){
		return false;
	}
	
	else {
		list -> addToHead(value);
		++set_size;
		return true;
	}
}

bool Set::remove(int value)
{
	if(!list -> contains(value)){
		return false;
	}
	
	else {
		list -> remove(value);
		--set_size;
		return true;
	}
}

void Set::clear()
{
	set_size = 0;
	delete list;
}

Set *Set::set_union (Set& parameterOfSet)
{
	Set *setunion = new Set();
	
	for(int i = 0; i < set_size; i++)
	{
		setunion -> add(this->list-> at(i));
	}
	
	for(int i = 0; i < parameterOfSet.set_size; i++)
	{
		setunion -> add(parameterOfSet.list->at(i));
	}
	
	return setunion;
}

Set *Set::intersection(Set& parameterOfSet)
{
	 Set *resultset = new Set();

	for(int i = 0; i < set_size; i++)
	{
		if(parameterOfSet.contains(list -> at(i)))
		resultset -> add(list -> at(i));
	}
	
	return resultset;
}

Set *Set::difference(Set& parameterOfSet)
{
	 Set *resultset = new Set();

	 for(int i = 0; i < set_size; i++)
	{
		if(!parameterOfSet.contains(list -> at(i)))
		resultset -> add(list -> at(i));
	}
		
	return resultset;
}
 
void Set::print()
{
	cout << "\n set contents(" << size() << ") :\t";
		
	for(int i = 0;i < size(); i++)
	cout << list -> at(i) << "\t";
		
}

int main()
{

	Set set1,set2;
	int z, x, c, v;
	cout << "Enter starting size of Set #1: ";
	cin >> z;
	cout << "Enter starting size of Set #2: ";
	cin >> x;
	cout << "Enter " << z << " values for Set #1: ";
	for(int i = 0; i < z; i++){
		cin >> c;
		set1.add(c);
	}
	cout << "Enter " << x << " values for Set #2: ";
	for(int i = 0; i < x; i++){
			cin >> v;
			set2.add(v);
	}
	cout<<"\nSet 1 : ";
	set1.print();
	cout<<"\nSet 2 :";
	set2.print();
	Set *setunion = set1.set_union(set2);
	cout<<"\nUnion set : ";
	setunion->print();
	Set *intersectionSet = set1.intersection(set2);
	cout<<"\nIntersection set : ";
	intersectionSet->print();
	Set *differenceSet1 = set1.difference(set2);
	cout<<"\nDifference set : Set1 - Set2 : ";
	differenceSet1->print();
	Set *differenceSet2 = set2.difference(set1);
	cout<<"\nDifference set : Set2 - Set1 : ";
	differenceSet2->print();

	
	
	return 0;
}
