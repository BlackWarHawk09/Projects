#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int A[13]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int max = A[0];

	
	cout << "\nmax = " << max << endl;

	system("pause");
	
	return 0;
}
