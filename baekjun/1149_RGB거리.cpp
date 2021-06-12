#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

int main()
{
	// 2���� �迭 DP Ȱ��
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int vec[1001][4];

	// �Է� �ޱ�
	for (int i = 1; i <= n; ++i) cin >> vec[i][1] >> vec[i][2] >> vec[i][3];


	// i�� ��ǥ �� j�� j��° ������ ������ ���
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			switch (j)
			{
			case 1:
				vec[i][j] = min(vec[i - 1][2] + vec[i][1], vec[i - 1][3] + vec[i][1]);
				break;
			case 2:
				vec[i][j] = min(vec[i - 1][1] + vec[i][2], vec[i - 1][3] + vec[i][2]);
				break;
			case 3:
				vec[i][j] = min(vec[i - 1][1] + vec[i][3], vec[i - 1][2] + vec[i][3]);
				break;
			}
		}
	}

	// �ּҰ� ���
	cout << min(min(vec[n][1], vec[n][2]), vec[n][3]) << "\n";

}