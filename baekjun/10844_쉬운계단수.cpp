#include <iostream>
using namespace std;
#include <cstring>
int dp[10][101];
#define MOD 1000000000

int solved(int curr, int digit)
{
	if (digit == 1) return 1;

	int& ref = dp[curr][digit];
	if (ref != -1) return ref;

	ref = 0;

	// ����Ҷ����� ������..
	if (curr != 9)
	{
		ref += solved(curr + 1, digit - 1);
		ref %= MOD;
	}
	if (curr != 0)
	{
		ref += solved(curr - 1, digit - 1);
		ref %= MOD;
	}
	return dp[curr][digit] = ref;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	int answer = 0;
	int n;
	cin >> n;

	// �������� ��������
	for (int i = 1; i <= 9; ++i)
	{
		answer += solved(i, n);
		answer %= MOD;
	}

	cout << answer << "\n";

	return 0;
}