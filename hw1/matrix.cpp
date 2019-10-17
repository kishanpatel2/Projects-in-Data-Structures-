//---------------------------------------------------------------------
// Name: Kishan Patel
// Email: kpp5282@psu.edu
// Class: CMPSC 122, Section 002
// Program 1.1
// Due Date: February 7, 2018, 11:59 PM
//
// Description: This program collects information from the user
// to create two matrices using a Matrix class definition, and
// performs several calculations using those matrices.
// The results of each calculation are retrieved and displayed
// to the user in a readable format.
//
// Acknowledgements:
// 1. Please use this portion of the banner comment to list
// any resources or individuals you consulted on the creation
// of this program.
//---------------------------------------------------------------------
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix{
	
	//Declare Member Fields For Rows And Columns
	int m, n;
	
	//Declare Member Field For Matrix Data
	int **mat;
	
public:
	
	//Declare Non-Default Constructors
	Matrix(int rows,int cols);
	Matrix(const Matrix &m); //Copy constructor
	
	//Declare Destructor
	~Matrix();
	
	//Declare Accessor Function
	const int getRows() const{return m;}
	const int getCols() const{return n;}
	
	//Declare Functions To Perform Calculations
	Matrix add(int& s) ;
	Matrix add(Matrix & m);
	
	Matrix subtract(int& s) ;
	Matrix subtract( Matrix & m);
	
	Matrix multiply(int& s) ;
	Matrix multiply( Matrix & m);
	
	Matrix divide(int& s) ;
	Matrix t() ; //transpose
	
	// Constructor Dynamically  Allocates 2D Array To Hold Matrix Data Based On Row/Col Size
	int & at(int r,int c) ;
	
	// Destructor Free Up Dynamically Allocated Memory Using Delete [], remember the "inside-out" rule
	const int &at (int r ,int col) const;
	
	//Operators overloaded
	friend std::ostream& operator << (std::ostream& out,const Matrix &m);
	friend std::istream& operator >> (std::istream& in, Matrix &m);
	
	Matrix operator + (int m);
	Matrix operator + (Matrix &m);
	Matrix operator - (int m);
	Matrix operator - (Matrix &m);
	Matrix operator * (int m);
	Matrix operator * (Matrix &m);
	Matrix operator / (int m);
	
	Matrix& operator = (const Matrix &m);

};

	//This is also a initializer list
	Matrix::Matrix(int r, int c) : m(r), n(c){
	
	mat = new int*[m];
	
	for (int i = 0; i < m; i++)
		mat[i] = new int[n];
	}

	Matrix::Matrix(const Matrix& ma){
	
	m = ma.getRows();
	n = ma.getCols();
	
	mat = new int*[m];
	
	for (int i = 0; i < m; i++)
		mat[i] = new int[n];
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = ma.at(i,j);
	
}


	Matrix::~Matrix()
{
	
	delete [] mat;
}

	Matrix Matrix::add(int& s)
{
	
	for (int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] += s;
	
	return *this;
	
}

	Matrix Matrix::add(Matrix &ma){
	
	int r = ma.getRows();
	int c = ma.getCols();
	
	if (r != m || c != n){
		std::cout << "Unable to add matrices of different size" << std::endl;
		return *this;
	}
	
	for (int i = 0; i < m; i++)
		for (int j = 0;j < n; j++)
			mat[i][j] += ma.at(i,j);
	
	return *this;
	
}

	Matrix Matrix::subtract(int& s)
{
	
	for (int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] -= s;
	
	return *this;
	
}

	Matrix Matrix::subtract(Matrix &ma){
	
	int r = ma.getRows();
	int c = ma.getCols();
	
	if(r != m || c != n){
		std::cout << "Unable to subtract matrices of different size" << std::endl;
		return *this;
	}
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] -= ma.at(i,j);
	
	return *this;
	
}

	Matrix Matrix::multiply(int& s)
{
	
	for (int i = 0; i < m; i++)
		for(int j = 0;j < n; j++)
			mat[i][j] *= s;
	
	return *this;
	
}

	Matrix Matrix::multiply(Matrix &ma){
	
	int r = ma.getRows();
	int c = ma.getCols();
	
	if(n != r){
		std::cout << "Unable to multiply matrices of incompatible size" << std::endl;
		return *this;
	}
	
	Matrix tmp (m, c);
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < c; j++)
			for (int k = 0; k < n; k++)
				tmp.at (i,j) += (mat[i][k]*ma.at(k,j));
	
	delete [] mat;
	*this = tmp;
	this -> n = c;
	
	return *this;
	
}

	Matrix Matrix::divide(int& s)
	{
	
	if(s == 0){
		std::cout << "Can't divide by 0" << std::endl;
		return *this;
	}
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] /= s;
	
	return *this;
	
}

	Matrix Matrix::t() //transpose
	{
	Matrix tmp(n, m);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			tmp.at(i,j) = mat[j][i];
	
	*this = tmp;
	
	return *this;
}

	Matrix Matrix::operator + (int s){
	
	return add(s);
}


	Matrix Matrix::operator + (Matrix& s){
	
	return add(s);
}

	Matrix Matrix::operator - (int s){
	
	return subtract(s);
}


	Matrix Matrix::operator - (Matrix& s){
	
	return subtract(s);
}

	Matrix Matrix::operator * (int s){
	
	return multiply(s);
}


	Matrix Matrix::operator * (Matrix& s){
	
	return multiply(s);
}

	Matrix Matrix::operator / (int s){
	
	return divide(s);
}

	std::ostream & operator << (std::ostream& out, const Matrix & ma){
	int m = ma.m;
	int n = ma.n;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0;j < n; j++){
			out << ma.mat[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

	std::istream & operator >> (std::istream& in,Matrix &ma)
{
	std::cout << "Please enter " << (ma.m * ma.n) << " values separated by spaces" << std::endl;
	
	for(int i = 0; i < ma.m; i++)
		for(int j = 0; j < ma.n; j++)
			in >> ma.mat[i][j];
	return in;
}

	Matrix& Matrix::operator = (const Matrix & ma){
	
	int r = ma.getRows();
	int c = ma.getCols();
	
	this -> m = r;
	this -> n = c;
	
	mat = new int * [m];
	
	for(int i = 0; i < m; i++)
		mat[i] = new int[n];
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = ma.at(i,j);
	
	return *this;
	
}


	int & Matrix::at(int r,int c)
{
	return mat[r][c];
}

	const int &Matrix::at(int r,int c) const{
	
	return mat[r][c];
}



	#endif

	#include <iostream>

	using namespace std;

	int main(void){
	Matrix m1(2,2),m2(2,2);
		
		cout << "Number of Rows in Matrix 1: 2" << endl;
		cout << "Number of Columns in Matrix 1: 2" << endl;
		cin >> m1;
		cout << endl;
		
		cout << "Number of Rows in Matrix 2: 2" << endl;
		cout << "Number of Columns in Matrix 2: 2" << endl;		
		cin >> m2;
		cout << endl;
			
		cout << "Written in Matrix Form: " << endl;
		
		cout << m1;
		cout << endl;
		cout << m2;
		
		cout << endl << "Matrix Addition" << endl;

		m1=m1+m2;
		
		m1=m1*2; 
		m2=m2*2;
		cout<<m1;
		
		m1=m1-m2;
		
		m1=m1*2; 
		m2=m2*2;
		cout<<m1;
		m1=m1*m2;
		m2=m1*m2;
		
		cout << endl << "After matrix multiplaction:" << endl << endl;
		cout<<"Matrix 1:"<< endl;
		cout << m1;
		cout << endl <<"Matrix 2:"<< endl;
		cout<<m2;
		cout << endl << "Resultant Matrix after multiplication:" << endl;
		cout<<m1;
		
		m1.t();
		cout << endl <<"Transposed matrix:"<<endl;
		cout<<m1;
		
	return 0;
}

