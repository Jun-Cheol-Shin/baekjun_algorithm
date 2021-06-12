#include <iostream>
using namespace std;
#include <cstring>
long long dp[91];

// 나누는 것이 없다면 long long으로 하자.
long long solved(int n)
{
	// 1자리 => 1개
	// 2자리 => 1개
	// 3자리 => 2개
	// 4자리 => 3개

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