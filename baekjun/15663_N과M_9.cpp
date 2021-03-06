#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9

int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

int n, m;

void solved(const vector<int>& vec, int curr)
{
	if (curr == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}

		cout << "\n";
		return;
	}

	int prev = -1;

	for (int i = 0; i < n; ++i)
	{
		if (!visited[i] && prev != vec[i])
		{
			visited[i] = true;
			arr[curr] = vec[i];
			prev = vec[i];
			solved(vec, curr + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<int> vec(n);

	for (int i = 0; i < n; ++i) cin >> vec[i];
	sort(vec.begin(), vec.end());

	solved(vec, 0);

	return 0;
}