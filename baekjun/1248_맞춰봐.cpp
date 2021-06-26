#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> answer;
int n;

//void test(const vector<vector<char>>& vec)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cout << vec[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}

bool condition(const vector<vector<char>>& vec, int count)
{
	for (int k = 0; k < count; ++k)
	{
		for (int j = k; j < count; ++j)
		{
			int sum = 0;
			for (int i = k; i <= j; ++i) sum += answer[i];

			if (vec[k][j] == '-' && sum >= 0) return false;
			if (vec[k][j] == '+' && sum <= 0) return false;
			if (vec[k][j] == '0' && sum != 0) return false;
		}
	}

	return true;
}

void solved(const vector<vector<char>>& vec, int count)
{
	if (count == n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		exit(0);
		//return;
	}

	for (int i = -10; i <= 10; ++i)
	{
		answer.push_back(i);
		if (condition(vec, count + 1))
		{
			solved(vec, count + 1);
		}
		answer.pop_back();
	}
}

int main()
{
	cin >> n;

	if (n > 0)
	{
		vector<vector<char>> vec;
		int length = n * (n + 1) / 2;
		list<char> s;

		for (int i = 0; i < length; ++i)
		{
			char a;
			cin >> a;
			s.push_back(a);
		}

		for (int i = 0; i < n; ++i)
		{
			vector<char> temp(n, '?');
			for (int j = i; j < n; ++j)
			{
				temp[j] = s.front();
				s.pop_front();
			}
			vec.push_back(temp);
		}

		//test(vec);
		solved(vec, 0);
	}

	return 0;
}