#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> op(4);

long long max_answer = -1000000000;
long long min_answer = 1000000000;

int getResult(int operate, int left, int right)
{
	switch (operate)
	{
	case 0:
		return left + right;
	case 1:
		return left - right;
	case 2:
		return left * right;
	case 3:
		return left / right;
	}
	
	return 0;
}

void solved(const vector<int>& vec, long long sum, int count)
{
	if (count == n)
	{
		max_answer = max(max_answer, sum);
		min_answer = min(min_answer, sum);

		return;
	}

	for(int i = 0; i < 4; ++i)
	{
		if (op[i] > 0)
		{
			op[i]--;
			solved(vec, getResult(i, sum, vec[count]), count + 1);
			op[i]++;
		}
	}
}

int main()
{

	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];
	for (int i = 0; i < 4; ++i) cin >> op[i];

	solved(vec, vec[0], 1);

	cout << max_answer << "\n" << min_answer;

	return 0;
}