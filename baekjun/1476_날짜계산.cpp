#include <iostream>
using namespace std;

int main()
{
	// E : 1 <= E <= 15
	// S : 1 <= S <= 28
	// M : 1 <= M <= 19
	int e, s, m;
	cin >> e >> s >> m;

	int answer = 0;

	while (e != 0 && s != 0 && m != 0)
	{
		--e;
		--s;
		--m;

		if (e == 0)
		{
			if(s != 0 || m != 0) e = 15;
		}
		if (s == 0)
		{
			if(e != 0 || m != 0) s = 28;
		}
		if (m == 0)
		{
			if(e != 0 || s != 0) m = 19;
		}
		++answer;

		//printf("%d %d %d => È½¼ö : %d\n", e, s, m, answer);
	}

	cout << answer << endl;


	return 0;
}