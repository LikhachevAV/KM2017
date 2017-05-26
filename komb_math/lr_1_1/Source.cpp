#include <iostream>

using namespace std;

int const LINE_NUMBER_WIDTH = 5;

void swap(int *a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
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

void PrintPermutation(int *t_arr, int t_arrSize)
{
	static int permutationNumber = 0;
	cout.width(LINE_NUMBER_WIDTH);
	cout << ++permutationNumber << ": ";
	for (int i = 0; i < t_arrSize; ++i)
	{
		cout << t_arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arrSize = 0, *arr;
	cout << "Please, enter arrays size: ";
	cin >> arrSize;
	arr = new int[arrSize];
	for (int i = 0; i < arrSize; ++i)
		arr[i] = i + 1;
	PrintPermutation(arr, arrSize);
	while (Permutate(arr, arrSize))
	{
		PrintPermutation(arr, arrSize);
	}
	cin.get();
	return 0;
}
