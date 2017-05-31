#include <iostream>
#include <time.h> 
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace chrono;

int const LINE_NUMBER_WIDTH = 5;

void swap(int *arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

bool Permutate(int *arr, int n)
{
	int j = n - 2;
	while (j != -1 && arr[j] >= arr[j + 1])
	{
		--j;
	}
	if (j == -1)
	{
		return false; // have not permutation
	}
	int k = n - 1;
	while (arr[j] >= arr[k])
	{
		--k;
	}
	swap(arr, j, k);
	int l = j + 1;
	int r = n - 1;
	while (l < r)
	{
		swap(arr, ++l, --r);
	}
	return true;
}

void PrintPermutation(int *t_arr, int t_arrSize)
{
	static int permutationNumber = 0;
	cout.width(LINE_NUMBER_WIDTH);
	cout << '#' << ++permutationNumber << ": ";
	for (int i = 0; i < t_arrSize; ++i)
	{
		cout << t_arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arrSize = 0;
	int *arr;
	cout << "Please, enter arrays size: ";
	if (!(cin >> arrSize) || arrSize < 1)
	{
		cout << "Array size must be int value, more than 0!\n";
		return 1;
	}
	arr = new int[arrSize];
	for (int i = 0; i < arrSize; ++i)
	{
		arr[i] = i + 1;
	}
	high_resolution_clock::time_point satrtTime = high_resolution_clock::now();
	high_resolution_clock::time_point permutationTime;
	duration<double> permutationDuration;
	do
	{
		PrintPermutation(arr, arrSize);
		permutationTime = high_resolution_clock::now();
		permutationDuration = duration_cast<duration<double>>(permutationTime - satrtTime);
		cout.precision(2);
		cout << "\tPermutation took " << permutationDuration.count() << " seconds" << endl << endl;
	} while (Permutate(arr, arrSize));
	cin.get();
	delete(arr);
	return 0;
}
