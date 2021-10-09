#include <bits/stdc++.h>

using namespace std;

bool canplace(int mat[][9], int i, int j, int no)
{
	// for the rows and coloums
	for (int k = 0; k < 9; k++)
	{
		if (mat[k][j] == no || mat[i][k] == no)
			return false;
	}

	// for sub grid
	int s1 = (i / 3) * 3;
	int s2 = (j / 3) * 3;
	for (int a = s1; a < s1 + 3; a++)
	{
		for (int b = s2; b < s2 + 3; b++)
		{
			if (mat[a][b] == no)
			{
				return false;
			}
		}
	}

	return true;
}

void printsudoku(int mat[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

bool solve(int mat[][9], int i, int j)
{

	//base case

	if (i == 9)
	{ //if row overflow
		printsudoku(mat);
		cout << endl << endl<< endl;
		return true;
	}

	//skip line if coloum overflow
	if (j == 9)
		return solve(mat, i + 1, 0);

	//skip cell if prefilled
	if (mat[i][j] != 0)
		return solve(mat, i, j + 1);

	//recursion

	for (int no = 1; no <= 9; no++)
	{ //place all possible
		if (canplace(mat, i, j, no))
		{ // check possibility
			mat[i][j] = no;

			if (solve(mat, i, j + 1)) //
				return true;
		}
	}
	// back
	mat[i][j] = 0;
	return false;
}

int main()
{
	int grid[9][9] =                 {{2, 0, 0, 0, 0, 0, 0, 0, 0},
					  {1, 0, 7, 4, 0, 0, 0, 0, 3},
					  {3, 0, 0, 2, 0, 0, 0, 5, 0},
					  {0, 0, 5, 0, 2, 0, 0, 0, 0},
					  {9, 6, 0, 1, 0, 0, 4, 0, 0},
					  {0, 0, 0, 0, 0, 7, 0, 0, 0},
					  {0, 0, 0, 0, 0, 3, 0, 0, 8},
					  {8, 0, 0, 6, 0, 0, 2, 0, 0},
					  {0, 4, 0, 8, 0, 0, 0, 3, 1}};

	solve(grid, 0, 0) ? cout << "Solved" : cout << "NO solution!!!";
	return 0;
}
