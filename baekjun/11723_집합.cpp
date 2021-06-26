#include <iostream>
using namespace std;
#define MAX 21

bool arr[MAX] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;

	int tmp;

	for (int i = 0; i < m; ++i)
	{
		string c;
		cin >> c;

		if (c == "all") for (int i = 1; i < MAX; ++i) arr[i] = true;
		else if (c == "empty") for (int i = 1; i < MAX; ++i) arr[i] = false;
		else
		{
			cin >> tmp;

			if (c == "add")	arr[tmp] = true;
			else if (c == "remove") arr[tmp] = false;
			else if (c == "toggle") arr[tmp] = !arr[tmp];
			else if (c == "check")
			{
				if (arr[tmp]) cout << "1" << "\n";
				else cout << "0" << "\n";
			}
		}
	}

}