#include <bits/stdc++.h>

using namespace std;

int maximum(int *A, int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max < A[i])
			max = A[i];
	}
	return max;
}

void countSort(int *A, int n)
{
	int max = maximum(A, n);
	int *count = new int(max + 1);
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		count[A[i]]++;
	}
	int i = 0, j = 0;
	while (i <= max)
	{
		if (count[i] > 0)
		{
			A[j] = i;
			count[i] = count[i] - 1;
			j++;
		}
		else
		{
			i++;
		}
	}

	for (i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
	exit(0);
}

int main()
{

	int n, x, arr[100];
	cout << "Enter the size of the array" << endl;
	cin >> n;
	cout << "Enter the elements of the array" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[i] = x;
	}

	countSort(arr, n);
	return 0;
}
