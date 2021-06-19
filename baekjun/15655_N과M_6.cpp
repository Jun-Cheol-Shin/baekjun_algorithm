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

	for (int i = left; i < n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[curr] = vec[i];
			solved(vec, curr + 1, i);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];
	sort(vec.begin(), vec.end(), less<int>());

	solved(vec, 0, 0);

	return 0;
}