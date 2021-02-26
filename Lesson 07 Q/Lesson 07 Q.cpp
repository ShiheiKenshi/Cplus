// Lesson 07 Q.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iomanip>
#include <iostream>
using namespace std;

//question 1

#define TRU(x, y) (((0)<= (x) & (x)<(y)) ? ("TRUE \n") : ("FALSE \n"))
//question 2
#define ARRUNIT(x,y) cout<< *&arr[x][y] << '\n'
//question 3
#define ARRSIZE(array, type) (sizeof(array)/(sizeof(type)))


void GenArr(int** arr, int a, int b) 
{
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			arr[i][j] = rand()%20;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char* argv[])
{
    //question 1
	int x, y;
	cout << "Enter value x & y: " << '\n';
	cin >> x >> y;

	cout<<TRU(x, y);

	//question 2

	int num1, num2;

	cout << "Enter new array [a][b] :" << '\n';
	cin >> num1 >> num2;

	int **arr = new int *[num1];
	for (int i = 0; i < num1; ++i)
	{
		arr[i] = new int[num2];
	}
	
	GenArr(arr, num1, num2);
	cout << "Enter string & column: " << '\n';
	int str, col;
	cin >> str >> col;
	ARRUNIT(str-1, col-1);

	//question3 
	char C[5];
	int I[7];
	double D[9];
	cout << "Question 3"<<'\n'
		 << "C="<< ARRSIZE(C, char)<<'\n'
		 << "I="<< ARRSIZE(I,int) << '\n'
		 << "D="<< ARRSIZE(D,double)<<'\n';


}
