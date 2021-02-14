#include <iostream>
#include<iomanip>
#include "Lesson 05 Q1.h"
#include "Lesson 05 Q2.h"
#include "Lesson 05 Q3.h"
#include "Lesson 05 Q4.h"
#include "Lesson 05 Q5.h"

using namespace std;
using namespace Lesson;

int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "ru");
	int q;

	cout << "�������� ������� 1-5: " << '\n';
	cin >> q;
	cout << '\n';
	switch (q)
	{
	case 1:
	{int x[5] = { 0,1,1,0,1 };
	cout << "����� ������:";
	masQ1(x);
	cout << endl;

	reversQ1(x);

	cout << "������� ������:";
	masQ1(x);
	break; }
	case 2:
	{
		int x[8];
		resQ2(x);
		break;
	}
	case 3:
	{
		size_t size;
		while (true)
		{
			cout << "������� ������ �������:" << endl;
			cin >> size;

			if (size > 1)
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������� ������� ��������. ������ ������ ���� ������ 1" << endl;
			}
		}
		int* x = new int[size];
		int y = size;
		cout << endl;
		masQ3(x, y);
		cout << "�������� ������: ";
		for (int i = 0; i < y; i++) //��������
		{
			cout << x[i] << ' ';
		}
		//cout << "check " << endl;
		checkQ3(x, y);
		cout << endl;
		bool z = checkQ3;
		break;
	}
	case 4:
	{
		size_t size;
		cout << "������� ������ �������:" << endl;
		cin >> size;
		int* a = new int[size];
		int b, c = size;
		masQ4(a, b, c);
		cout << "������ ������: ";
		for (int i = 0; i < c; i++) //��������
		{
			cout << a[i] << ' ';
		}
		cout << endl;
		//cout << b << endl; // ��������
		resQ4(a, b, c);
		break;
	}
	case 5:
	{
		size_t size;
		cout << "������� ������ �������:" << endl;
		cin >> size;
		int* x = new int[size];
		int y = size;
		inpQ5(x, y);
		cout << endl;
		cout << "������ ������:";
		masQ5(x, y);

		reversQ5(x);

		cout << "������� ������:";
		masQ5(x, y);
		break;
	}

	default:
		cout << "���������� ������ ����� �� 1 �� 5:" << '\n';
	}
}