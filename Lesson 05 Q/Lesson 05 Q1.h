// Lesson 05 Q.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

namespace Lesson
{
	void masQ1(int* a) //����� ������� �� �����
	{
		for (int i = 0; i < 5; i++)
		{
			cout << a[i] << ' ';
		}

	};

	void reversQ1(int* arr) //������ 0 � 1
	{

		for (int i = 0; i < 5; i++)
		{
			//(arr[i] == 1) ? 0 : 1; ������ �� �� ��������
			if (arr[i] == 1)
			{
				arr[i] = 0;
			}
			else
			{
				arr[i] = 1;
			}
			//cout << arr[i] << " ";
		}
		cout << endl;

	};
}

/*int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "ru");
	int x[5] = { 0,1,1,0,1 };
	cout << "����� ������:";
	mas(x);
	cout << endl;
	
	revers(x);
	
	cout << "������� ������:";
	mas(x);
}*/