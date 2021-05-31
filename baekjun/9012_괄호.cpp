#include <iostream>
using namespace std;
#include <string>
#include <vector>

int main()
{
	vector<char> Vec;
	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		Vec.clear();
		string a;
		getline(cin, a);

		for (int j = 0; j < a.length(); ++j)
		{
			if (Vec.size() > 0 && Vec.back() == '(' && Vec.back() != a[j])
			{
				Vec.pop_back();
			}
			else
			{
				Vec.push_back(a[j]);
			}
		}

		if (Vec.size() > 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}