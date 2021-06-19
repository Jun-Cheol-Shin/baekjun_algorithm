#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 8

int arr[MAX] = { 0, };
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

	for (int i = 0; i < n; ++i)
	{
		arr[curr] = vec[i];
		solved(vec, curr + 1);
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