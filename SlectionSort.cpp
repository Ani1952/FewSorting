#include <bits/stdc++.h>

using namespace std;

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
			swap(a[j], a[min]);
		}
		printf(" Pass No %d",i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
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

	SelectionSort(arr, n);
	return 0;
}
