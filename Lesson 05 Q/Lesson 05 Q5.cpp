#include <iostream>
using namespace std;

void inp (int* a, int b) //���� �������
{
	cout << "������� ������������� ������ �� 0 � 1" << endl;
	for (int i = 0; i < b; i++)
	{
		while (true) //�������� �� ����
		{
			cout << "������� ������� " << (i + 1) << " ";
			cin >> a[i];
			if (a[i] > 1 || a[i] < 0)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������� ������� ��������. ������� ����� ���� ������ 1 ��� 0" << endl;
			}
			else
			{
				break;
			}
		}
	}

};

void mas(int* a, int b) //����� ������� �� �����
{
	for (int i = 0; i < b; i++)
	{
		cout << a[i] << ' ';
		
	}

};


void revers(int* arr) //������ 0 � 1
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
	}
	cout << endl;

};

int main(int argc, const char* argv[])
{
	size_t size;
	setlocale(LC_ALL, "ru");
	cout << "������� ������ �������:" << endl;
	cin >> size;
	int* x = new int[size];
	int y = size;
	inp (x,y);
	cout << endl;
	cout << "������ ������:";
	mas(x,y);
	
	revers(x);

	cout << "������� ������:";
	mas(x,y);
}