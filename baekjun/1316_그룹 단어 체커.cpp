#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{

	int answer = 0;
	int N;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		bool flag = false;
		string a;
		cin >> a;

		// 2���ڱ����� ������ �׷� �ܾ�
		for (int j = 2; j < a.length(); ++j)
		{
			for (int k = 0; k < j - 1; ++k)
			{
				// �׷� �ܾ �ƴ� ��
				if (a[k] == a[j] && a[j] != a[j-1])
				{
					flag = true;
					break;
				}
			}

			if (flag) break;
		}

		if(!flag) ++answer;
	}

	printf("%d", answer);

	return 0;
}