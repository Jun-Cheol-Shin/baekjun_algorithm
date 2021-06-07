#include <iostream>
using namespace std;
#define MAX 10000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int* numVec = (int*)calloc(MAX, sizeof(int));
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int number;
		cin >> number;
		numVec[number - 1]++;
	}

	for (int i = 0; i < MAX; ++i)
	{
		if (numVec[i] && numVec[i] > 0)
		{
			for (int j = 0; j < numVec[i]; ++j) printf("%d\n", i + 1);
		}
	}

	free(numVec);

}