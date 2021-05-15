#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Checkprime(int n)
{
	if (n < 2) return false;

	for (int i = n / 2; i >= 2; --i)
	{
		if (n % i == 0) return false;
	}

	//cout << n << "Àº ¼Ò¼ö" << endl;
	return true;
}

int main()
{
	int N;

	cin >> N;
	int result = 0;

	for (int i = 0; i < N; ++i)
	{
		int number;
		cin >> number;

		if (Checkprime(number)) ++result;
	}

	cout << result << endl;
}