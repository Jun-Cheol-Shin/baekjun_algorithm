// 중요 문제!!!!!!!!

#include <iostream>
#include <cstring>
using namespace std;

int n;
int answer = 0;
bool check[15][15];

void print(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}

bool possible(int current_y, int current_x)
{
	for (int i = 0; i < current_y; ++i)
	{
		// 세로로 같은 경우..
		if (check[i][current_x]) return false;

		// 대각선으로 같은 경우..
		int check_x = current_x - (current_y - i);
		int check_xx = current_x + (current_y - i);

		if (check_x < n && check_x >= 0 && check[i][check_x]) return false;
		if (check_xx < n && check_xx >= 0 && check[i][check_xx]) return false;
	}

	return true;
}

void solved(int queen_count)
{
	//print(n);

	if (queen_count == n)
	{
		answer++;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (possible(queen_count, i))
		{
			check[queen_count][i] = true;
			solved(queen_count + 1);
			check[queen_count][i] = false;
		}
	}
}

int main()
{
	memset(check, false, sizeof(check));
	cin >> n;
	solved(0);

	cout << answer;

	return 0;
}