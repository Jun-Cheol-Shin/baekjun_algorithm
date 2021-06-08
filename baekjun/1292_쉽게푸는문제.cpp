#include <iostream>
using namespace std;
#define MAX 1000

int main()
{
	int arr[1001];

	int idx = 1;
	int number = 1;

	while (idx <= MAX)
	{
		for (int i = 0; i < number && idx <= MAX; ++i)
		{
			arr[idx++] = number;
		}
		number++;
	}

	int answer = 0;
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; ++i)
	{
		answer += arr[i];
	}

	cout << answer;

	return 0;
}