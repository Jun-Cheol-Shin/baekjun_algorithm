#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 1000000

int goHundred(int n)
{
	return abs(n - 100);
}

int getLength(int n)
{
	string a = to_string(n);
	return a.length();
}

bool GoPossible(int n, const vector<int>& broken)
{
	if (n == 0)
	{
		// 못 찾았을 경우 end 리턴
		if (find(broken.begin(), broken.end(), 0) != broken.end())
		{
			return false;
		}
	}

	else
	{
		while (n)
		{
			if (find(broken.begin(), broken.end(), n % 10) != broken.end())
			{
				return false;
			}
			n /= 10;
		}
	}

	return true;
}

int Check(int goal, const vector<int>& broken)
{
	int count = INF;
	int channel;

	for (int i = 0; i < MAX; ++i)
	{
		if (GoPossible(i, broken))
		{
			int value = abs(goal - i);

			if (value < count)
			{
				count = value;
				channel = i;
			}
		}
	}

	return count + getLength(channel);
}


int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> broken(m);
	for (int i = 0; i < m; ++i) cin >> broken[i];


	cout << min(Check(n, broken), goHundred(n)) << endl;

	return 0;
}