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

	cout << "Выберите задание 1-5: " << '\n';
	cin >> q;
	cout << '\n';
	switch (q)
	{
	case 1:
	{int x[5] = { 0,1,1,0,1 };
	cout << "Задан массив:";
	masQ1(x);
	cout << endl;

	reversQ1(x);

	cout << "Получен массив:";
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
			cout << "Введите размер массива:" << endl;
			cin >> size;

			if (size > 1)
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Неверно внесено значение. Размер должен быть больше 1" << endl;
			}
		}
		int* x = new int[size];
		int y = size;
		cout << endl;
		masQ3(x, y);
		cout << "Заданный массив: ";
		for (int i = 0; i < y; i++) //проверка
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
		cout << "Введите размер массива:" << endl;
		cin >> size;
		int* a = new int[size];
		int b, c = size;
		masQ4(a, b, c);
		cout << "Старый массив: ";
		for (int i = 0; i < c; i++) //проверка
		{
			cout << a[i] << ' ';
		}
		cout << endl;
		//cout << b << endl; // проверка
		resQ4(a, b, c);
		break;
	}
	case 5:
	{
		size_t size;
		cout << "Введите размер массива:" << endl;
		cin >> size;
		int* x = new int[size];
		int y = size;
		inpQ5(x, y);
		cout << endl;
		cout << "Введен массив:";
		masQ5(x, y);

		reversQ5(x);

		cout << "Получен массив:";
		masQ5(x, y);
		break;
	}

	default:
		cout << "Необходимо ввести цифру от 1 до 5:" << '\n';
	}
}