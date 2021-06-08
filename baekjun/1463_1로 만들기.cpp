#include <iostream>
#include <cstring>
using namespace std;

int d[1000001];

void makeOne(int X)
{

	// �ݷ�
	// 100000 -> 18 ���;���
	// 1284 => 11

	// 0�� 1�� 0
	d[0] = 0;
	d[1] = 0;

	for (int i = 2; i <= X; ++i)
	{
		// -1 ���� 1ȸ �߰�
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