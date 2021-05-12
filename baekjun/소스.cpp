#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<string> croatia = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };


	int count = 0;
	string N;
	getline(cin, N);

	int answer = 0;

	while (count != N.length())
	{
		for (int j = 0; j < croatia.size(); ++j)
		{
			string cmp = croatia[j];

			for (int k = 0; k < cmp.length(); ++k)
			{

			}
		}
	}

	printf("%d", answer);

	return 0;
}