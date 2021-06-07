#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int num[1000000] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> answer(n, -1);
	vector<int> vec(n);
	stack<int> _stack;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
		++num[vec[i] - 1];
	}

	for (int i = 0; i < n; ++i)
	{
		while (!_stack.empty() && num[vec[i] - 1] > num[vec[_stack.top()] - 1])
		{
			answer[_stack.top()] = vec[i];
			_stack.pop();
		}
		_stack.push(i);
	}

	for (int i = 0; i < n; ++i) cout << answer[i] << " ";

	return 0;
}