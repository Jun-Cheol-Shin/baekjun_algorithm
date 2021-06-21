#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 16


bool flag = false;
char arr[MAX];
bool visited[MAX] = { false, };
int l, c;

bool check(char* arr, int count)
{
	bool vowel = false;
	int c = 0;
	bool consonant = false;

	for (int i = 0; i < count; ++i)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'i')
			vowel = true;
		else
		{
			c++;
		}
	}

	return c > 1 && vowel;
}

void solved(const vector<char>& vec, int curr, int left)
{
	if (curr == l)
	{
		if (!check(arr, curr)) return;
		for (int i = 0; i < l; ++i)
		{
			cout << arr[i];
		}
		cout << "\n";
		return;
	}


	for (int i = left; i < c; ++i)
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;

	vector<char> vec(c);
	for (int i = 0; i < c; ++i) cin >> vec[i];
	sort(vec.begin(), vec.end());

	solved(vec, 0, 0);

	return 0;
}