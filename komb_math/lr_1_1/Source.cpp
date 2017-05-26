#include <iostream>

using namespace std;

int const LINE_NUMBER_WIDTH = 5;

void swap(int *a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool Permutate(int *a, int n)
{
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1])
	{
		--j;
	}
	if (j == -1)
	{
		return false; // have not permutation
	}
	int k = n - 1;
	while (a[j] >= a[k])
	{
		--k;
	}
	swap(a, j, k);
	int l = j + 1;
	int r = n - 1;
	while (l < r)
	{
		swap(a, ++l, --r);
	}
	return true;
}

void PrintPermutation(int *a, int n)
{
	static int num = 0; // номер перестановки
	cout.width(LINE_NUMBER_WIDTH);
	cout << ++num << ": ";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n = 0, *a;
	cout << "Please, enter arrays size: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
	PrintPermutation(a, n);
	while (Permutate(a, n))
	{
		PrintPermutation(a, n);
	}
	cin.get();
	return 0;
}
