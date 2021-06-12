#include <iostream>
using namespace std;
#include <cstring>
long long dp[91];

// ������ ���� ���ٸ� long long���� ����.
long long solved(int n)
{
	// 1�ڸ� => 1��
	// 2�ڸ� => 1��
	// 3�ڸ� => 2��
	// 4�ڸ� => 3��

	if (n == 1) return 1;
	else if (n == 2) return 1;
	
	if (dp[n] != -1) return dp[n];
	return dp[n] = solved(n - 1) + solved(n - 2);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;

	cout << solved(n) << "\n";

	return 0;
}