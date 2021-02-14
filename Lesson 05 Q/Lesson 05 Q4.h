#include <iostream>
using namespace std;

namespace Lesson
{
	void masQ4(int* a, int& b, int c) //ввод массива
	{
		cout << "Введите целочисленный массив" << endl;
		for (int i = 0; i < c; i++)
		{
			cout << "Элемент массива " << (i + 1) << " ";
			cin >> a[i];
		}
		cout << "Введите число сдвига:" << endl;
		cin >> b;
	};

	void rotateQ4(int* arr, int y)
	{
		int r = arr[0];
		for (int i = 0; i < y - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[y - 1] = r;
	}


	void resQ4(int* arr, int x, int y) // сдвиг массива
	{
		setlocale(LC_ALL, "ru");
		cout << "Новый массив: ";

		for (int i = 0; i < x; i++)
		{
			rotateQ4(arr, y);
		}
		for (int i = 0; i < y; i++)
		{
			cout << arr[i] << " ";
		}
	};
}

/*int main(int argc, const char* argv[])
{
	size_t size;
	setlocale(LC_ALL, "ru");
	cout << "Введите размер массива:" << endl;
	cin >> size;
	int* a = new int[size];
	int b, c = size;
	mas(a, b, c);
	cout << "Старый массив: ";
	for (int i = 0; i < c; i++) //проверка
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	//cout << b << endl; // проверка
	res(a, b, c);
}*/
