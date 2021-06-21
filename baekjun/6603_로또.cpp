#include <iostream>
using namespace std;
#include <vector>
#define LOTTO 6
#define MAX 13

int T;
bool visited[MAX] = { false, };
int arr[LOTTO] = { 0, };

void solved(const vector<int>& vec, int curr, int left)
{
	if (curr == LOTTO)
	{
		for (int i = 0; i < LOTTO; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = left; i < T; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[curr] = vec[i];
			solved(vec, curr + 1, i);
			visited[i] = false;
		}

		if (T - i < LOTTO && curr == 0) return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		cin >> T;
		if (T == 0)break;

		vector<int> vec(T);
		for (int i = 0; i < T; ++i)	cin >> vec[i];
		solved(vec, 0, 0);
		cout << "\n";
	}

	return 0;
}