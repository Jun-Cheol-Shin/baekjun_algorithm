#include <iostream>
using namespace std;
#include <vector>
#include <cstring>

#define MAX 1000001
int check[MAX] = { true, };

void Goldbach(int number)
{
	for (int i = number - 3; i > 2; i -= 2)
	{
		if (check[i] && check[number - i])
		{
			cout << number << " = " << number - i << " + " << i << "\n";
			return;
		}
	}

	cout << "Goldbach's conjecture is wrong." << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(check, true, sizeof(check));

	check[1] = false;
	check[2] = false;

	for (int i = 2; i * i < MAX; ++i)
	{
		if (check[i])
		{
			for (int j = i + i; j < MAX; j += i) check[j] = false;
		}
	}

	int number;
	while (1)
	{
		cin >> number;
		if (number == 0)break;

		Goldbach(number);
	}

	return 0;
}