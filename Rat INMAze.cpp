#include <bits/stdc++.h>

using namespace std;

bool safe(int a[][4], int x, int y, int n)
{
	if (x < n and y < n and a[x][y] == 1)
	{
		return true;
	}
	return false;
}

bool solve(int a[][4], int b[][4], int x, int y, int n)
{

	if (x == n - 1 and y == n - 1)
	{
		b[x][y] = 1;
		return true;
	}

	if (safe(a, x, y, n))
	{
		b[x][y] = 1;

		if (solve(a, b, x, y + 1, n))
			return true;

		if (solve(a, b, x + 1, y, n))
			return true;

		b[x][y] = 0;
		return false;
	}

	return false;
}

int main()
{

	int a[4][4] = {{1, 1, 1, 1},
				   {1, 1, 0, 1},
				   {0, 1, 0, 1},
				   {1, 1, 1, 1}};

	int b[4][4] = {0};
	solve(a, b, 0, 0, 4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
