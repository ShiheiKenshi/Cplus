#include <iostream>
#include<iomanip>
using namespace std;

void mas(int* a, int b) //���� �������
{
	cout << "������� ������������� ������" << endl;
	for (int i = 0; i < b; i++)
	{
		cout << "������� ������� " << (i + 1) << " ";
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
	cout << "���������: " << d << endl;
	return 1;
};

int main(int argc, const char* argv[])
{
	size_t size;
	setlocale(LC_ALL, "ru");
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
		cout <<endl;
	mas(x, y);
	cout << "�������� ������: ";
	for (int i = 0; i < y; i++) //��������
	{
		cout << x[i] << ' ';
	}
	cout << "check " << endl;
	check(x, y);
	cout << endl;
	bool z = check;
	/*cout << boolalpha;
	cout << "���������: "<< z << endl;*/
}