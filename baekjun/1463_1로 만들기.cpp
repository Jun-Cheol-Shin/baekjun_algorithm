#include <iostream>
#include <cstring>
using namespace std;

int d[1000001];

void makeOne(int X)
{

	// ¹Ý·Ê
	// 100000 -> 18 ³ª¿Í¾ßÇÔ
	// 1284 => 11

	// 0°ú 1Àº 0
	d[0] = 0;
	d[1] = 0;

	for (int i = 2; i <= X; ++i)
	{
		// -1 »¬¼À 1È¸ Ãß°¡
		d[i] = d[i - 1] + 1;

		if (i % 3 == 0)
		{
			d[i] = min(d[i / 3] + 1, d[i]);
		}

		if (i % 2 == 0)
		{
			d[i] = min(d[i / 2] + 1, d[i]);
		}
	}

	cout << d[X];
}

int main()
{
	int X;
	cin >> X;
	memset(d, -1, sizeof(d));
	makeOne(X);
}