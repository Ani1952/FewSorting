#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}
	return a.length() < b.length();
}

void sorting(char *in, char *out, int i, int j, vector<string> &l)
{
	if (in[i] == '\0')
	{
		out[j] = '\0';
		string t(out);
		l.push_back(t);
		return;
	}

	out[j] = in[i];

	sorting(in, out, i + 1, j + 1, l);
	sorting(in, out, i + 1, j, l);
}

int main()
{
	char input[100], output[100];
	vector<string> list;
	cin >> input;
	sorting(input, output, 0, 0, list);
	sort(list.begin(), list.end(), comp);

	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << ",";
	}
	return 0;
}
