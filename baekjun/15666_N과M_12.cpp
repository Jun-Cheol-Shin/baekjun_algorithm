#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { false, };

void solved(const vector<int>& vec, int curr, int left)
{
	if (m == curr)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = -1;

	for (int i = left; i < n; ++i)
	{
		if (prev != vec[i])
		{
			arr[curr] = vec[i];
			prev = vec[i];
			solved(vec, curr + 1, i);
		}
	}
}

int main()
{
	cin >> n >> m;
	vector<int> vec(n);

	for (int i = 0; i < n; ++i) cin >> vec[i];
	sort(vec.begin(), vec.end());

	solved(vec, 0, 0);

	return 0;
}