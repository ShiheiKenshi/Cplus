#include <iostream>
#include<iomanip>
using namespace std;

void mas(int* a, int b) //ввод массива
{
	cout << "Введите целочисленный массив" << endl;
	for (int i = 0; i < b; i++)
	{
		cout << "Элемент массива " << (i + 1) << " ";
		cin >> a[i];
	}
}

bool check(int* a,int b)
{
	int left = 0, right=0, c;
	bool d = 0;
	
	for (int i = 0; i < b; i++)
		{
			left += a[i];
			cout << "left 1 " << left << endl;
			for (int j = 0; j < b; j++)
			{
				//right += (j > i) ? a[j] : 0;
				if (j > i)
				{
					right = right + a[j];
				}
				else
				{
					right = right + 0;
				}
				cout << "right 1 " << right << endl;
			}
			cout << "left 2 " << left << endl;
			cout << "right 2 " << right << endl;
			if (left == right)
			{
				c = 1;
			}
			else
			{
				c = 0;
			}
			cout << c << endl;
			right = 0;
			if (c!=0)
			{
				d = c;
			}
		}
		
		
	cout << boolalpha;
	cout << "Результат: " << d << endl;
	return 1;
};

int main(int argc, const char* argv[])
{
	size_t size;
	setlocale(LC_ALL, "ru");
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
		cout <<endl;
	mas(x, y);
	cout << "Заданный массив: ";
	for (int i = 0; i < y; i++) //проверка
	{
		cout << x[i] << ' ';
	}
	cout << "check " << endl;
	check(x, y);
	cout << endl;
	bool z = check;
	/*cout << boolalpha;
	cout << "Результат: "<< z << endl;*/
}