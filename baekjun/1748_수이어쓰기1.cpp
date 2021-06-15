#include <iostream>
using namespace std;
#include <string>

int main()
{
	int val = 0;
	int digit = 1;
	int num = 9;

	long long answer = 0;

	string sn;
	int n;
	cin >> n;

	sn = to_string(n);

	for (int i = 1; i < sn.length(); ++i)
	{
		val += num;
		answer += (long long)num * digit;
		num *= 10;
		digit++;
	}

	int a = n - val;
	answer += (long long)a * digit;

	cout << answer << endl;

	return 0;
}