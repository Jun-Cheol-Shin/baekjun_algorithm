#include <iostream>
using namespace std;
#include <vector>
#include <cstring>

bool check[51][51];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}

bool enableIndex(int row, int col, int n)
{
	return row >= 0 && row < n&& col >= 0 && col < n;
}

int checkMax(const vector<vector<char>>& vec)
{
	int maxSize = vec.size();
	int retval = 1;

	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec.size(); ++j)
		{
			char val = vec[i][j];

			for (int k = 0; k < 4; ++k)
			{
				int temp = 1;
				int cy = i + dy[k];
				int cx = j + dx[k];

				while (enableIndex(cy, cx, maxSize) && vec[cy][cx] == val)
				{
					temp++;
					cy += dy[k];
					cx += dx[k];
				}

				retval = max(retval, temp);
			}
		}
	}

	return retval;
}

int main()
{
	memset(check, false, sizeof(check));
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<vector<char>> vec;
	vector<vector<char>> temp;

	int answer = 1;

	for (int i = 0; i < n; ++i)
	{
		vector<char> tmp(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> tmp[j];
		}
		vec.push_back(tmp);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char val = vec[i][j];

			for (int k = 0; k < 4; ++k)
			{
				int cy, cx;
				cy = i + dy[k];
				cx = j + dx[k];

				if (enableIndex(cy, cx, n) && vec[cy][cx] != val && !check[cy][cx])
				{
					temp.clear();
					temp = vec;
					swap(temp[cy][cx], temp[i][j]);
					answer = max(checkMax(temp), answer);
				}
			}
			check[i][j] = true;
		}
	}

	cout << answer << endl;


	return 0;
}