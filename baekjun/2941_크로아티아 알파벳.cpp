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

	while (count <= N.length() - 1)
	{
		bool flag = false;

		for (int j = 0; j < croatia.size(); ++j)
		{
			string cmp = croatia[j];
			string cmp2 = N.substr(count, cmp.length());

			if (!cmp.compare(cmp2)) 
			{
				//cout << cmp << endl;
				flag = true;
				count += cmp.length();
				break;
			}
		}

		if (!flag)
		{
			//cout << N[count] << endl;
			++count;
		}
		++answer;
	}

	printf("%d", answer);

	return 0;
}