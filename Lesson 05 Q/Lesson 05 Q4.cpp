#include <iostream>
using namespace std;

void mas(int* a, int& b, int c) //���� �������
{
	cout << "������� ������������� ������" << endl;
	for (int i = 0; i < c; i++)
	{	
		cout << "������� ������� " << (i+1) << " ";
		cin >> a[i];
	}
	cout << "������� ����� ������:" << endl;
	cin >> b;
};


void rotate(int* arr, int y)
{
	int r = arr[0];
	for (int i = 0; i < y - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
		arr[y - 1] = r;
}

void res(int*arr,int x, int y) // ����� �������
{
	setlocale(LC_ALL, "ru");
	cout << "����� ������: ";

	for (int i = 0; i < x; i++)
	{
		rotate(arr, y);
	}
	for (int i = 0; i < y; i++)
	{
		cout << arr[i] << " ";
	}
};

int main(int argc, const char* argv[])
{
	size_t size;
	setlocale(LC_ALL, "ru");
	cout << "������� ������ �������:" << endl;
	cin >> size;
	int* a = new int[size];
	int b, c = size;
	mas(a, b, c);
	cout << "������ ������: ";
	for (int i = 0; i < c; i++) //��������
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	
	//cout << b << endl; // ��������
	res(a, b, c);
	
}
