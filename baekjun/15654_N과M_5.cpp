#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#define MAX 9
int n, m;

int arr[MAX] = { 0, };
bool visited[MAX] = { false, };

void solved(int cm, const vector<int>& vec)
{
	if (cm == m)
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
		if (!visited[i])
		{
			visited[i] = true;
			arr[cm] = vec[i];
			solved(cm + 1, vec);
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

	solved(0, vec);

	return 0;
}