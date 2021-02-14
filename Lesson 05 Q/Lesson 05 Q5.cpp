#include <iostream>
using namespace std;

void inp (int* a, int b) //ввод массива
{
	cout << "Введите целочисленный массив из 0 и 1" << endl;
	for (int i = 0; i < b; i++)
	{
		while (true) //проверка на ввод
		{
			cout << "Элемент массива " << (i + 1) << " ";
			cin >> a[i];
			if (a[i] > 1 || a[i] < 0)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Неверно внесено значение. Элемент может быть только 1 или 0" << endl;
			}
			else
			{
				break;
			}
		}
	}

};

void mas(int* a, int b) //вывод массива на экран
{
	for (int i = 0; i < b; i++)
	{
		cout << a[i] << ' ';
		
	}

};


void revers(int* arr) //замена 0 и 1
{

	for (int i = 0; i < 5; i++)
	{
		//(arr[i] == 1) ? 0 : 1; Почему то не работает
		if (arr[i] == 1)
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = 1;
		}
	}
	cout << endl;

};

int main(int argc, const char* argv[])
{
	size_t size;
	setlocale(LC_ALL, "ru");
	cout << "Введите размер массива:" << endl;
	cin >> size;
	int* x = new int[size];
	int y = size;
	inp (x,y);
	cout << endl;
	cout << "Введен массив:";
	mas(x,y);
	
	revers(x);

	cout << "Получен массив:";
	mas(x,y);
}