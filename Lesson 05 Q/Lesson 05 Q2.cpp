#include <iostream>
using namespace std;

void res(int* arr)
{
	for (int i = 0; i < 8; i++)
	{
		arr[i] = i * 3+1;
		cout << arr[i] << " ";
	}
};

int main(int argc, const char* argv[])
{
	int x[8];
	res(x);
}