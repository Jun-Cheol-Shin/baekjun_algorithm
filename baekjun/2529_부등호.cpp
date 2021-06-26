#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define MAX 10
bool visited[MAX] = { false, };

int n;
long long _max = 0;
long long _min = 9876543210;

string answer_max = "";
string answer_min = "";

void solved(const vector<char>& vec, int curr, int count, string number, long long inum)
{
	if (count == n)
	{
		_max = max(_max, inum);
		_min = min(_min, inum);

		if (_max == inum) answer_max = number;
		if (_min == inum) answer_min = number;

		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (i != curr && !visited[i])
		{
			if (vec[count] == '<' && curr < i)
			{
				visited[i] = true;
				solved(vec, i, count + 1, number + to_string(i), inum + (i * pow(10, n - (count + 1))));
				visited[i] = false;
			}

			else if (vec[count] == '>' && curr > i)
			{
				visited[i] = true;
				solved(vec, i, count + 1, number + to_string(i), inum + (i * pow(10, n - (count + 1))));
				visited[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n;

	vector<char> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];

	for (int i = 0; i < 10; ++i)
	{
		visited[i] = true;
		solved(vec, i, 0, to_string(i), i * pow(10, n));
		visited[i] = false;
	}

	cout << answer_max << "\n";
	cout << answer_min;

}