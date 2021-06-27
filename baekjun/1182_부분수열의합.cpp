#include <iostream>
#include <vector>
using namespace std;
#define MAX 21

int answer = 0;
int n, s;

void solved(const vector<int>& vec, int curr, int sum)
{
	if (n == curr) return;
	if (sum + vec[curr] == s) answer++;

	solved(vec, curr + 1, sum + vec[curr]);
	solved(vec, curr + 1, sum);
}

int main()
{
	cin >> n >> s;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];


	solved(vec, 0, 0);
	cout << answer << "\n";

	return 0;
}