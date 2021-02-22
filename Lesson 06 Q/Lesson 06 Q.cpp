// Lesson 06 Q.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include <random>

using namespace std;

string txt() 
{
	string box("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz");
	random_device x;
	mt19937 generator(x());
	shuffle(box.begin(), box.end(), generator);
	return box.substr(0,50);
}


int main()
{
	//question 1
	{
		string a1 = txt();
		string a2 = txt();

		ofstream first;
		first.open("C:\\Lesson 06 Q\\first.txt");
		first << "Welcome \n" << a1 << '\n' << "Bye" << '\n';
		first.close();

		ofstream second;
		second.open("C:\\Lesson 06 Q\\second.txt");
		second << "Continue \n" << a2 << '\n' << "Goodbye" << '\n';
		second.close();
	}
	//question 2
	{
		ifstream sum, sum1;



		int l, l1;
		char* f;
		char* f1;

		sum.open("C:\\Lesson 06 Q\\first.txt");
		sum.seekg(0, ios::end);
		l = sum.tellg();
		sum.seekg(0, ios::beg);

		f = new char[l];

		sum.read(f, l);
		sum.close();
		cout.write(f, l);


		sum1.open("C:\\Lesson 06 Q\\second.txt");
		sum1.seekg(0, ios::end);
		l1 = sum1.tellg();
		sum1.seekg(0, ios::beg);

		f1 = new char[l1];

		sum1.read(f1, l1);
		sum1.close();
		cout.write(f1, l1);


		ofstream sum2;
		sum2.open("C:\\Lesson 06 Q\\sum.txt");
		sum2 << f << f1;
		sum2.close();
		delete[]f;
		delete[]f1;
	}
	//question 3
	{
	char* b;
	int l2, z = 0;
	ifstream q;
	string S;

	q.open("C:\\Lesson 06 Q\\sum.txt");
	q.seekg(0, ios::end);
	l2 = q.tellg();
	q.seekg(0, ios::beg);

	b = new char[l2];

	q.read(b, l2);
	q.close();
	cin >> S;
	char* k = const_cast<char*>(S.c_str());

	cout << strstr(b, k);
	}
}