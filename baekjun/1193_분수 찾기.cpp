#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N; 
	cin >> N;

	// 1/1
	// 1/2, 2/1
	// 3/1, 2/2, 1/3
	// 1/4, 2/3, 3/2, 4/1
	// 5/1, 4/2, 3/3, 2/4, 1/5
	// 1/6, 2/5, 3/4, 4/3, 5/2, 6/1

	// ���� = ¦���϶� �и� count, Ȧ���϶� ���ڰ� count
	// ��  = ¦���϶� ���ڰ� count, Ȧ���϶� �и� count

	int c = 1;
	int count = 1;
	int denominator = 1;			// �и�
	int numerator = 1;				// ����

	for (int i = 1; i < N; ++i)
	{
		// ���� ��
		if (c == count)
		{
			// �ʱ�ȭ
			c = 1;
			++count;
			if (count & 1)
			{
				numerator = count;
				denominator = 1;
			}
			else
			{
				numerator = 1;
				denominator = count;
			}
		}

		else
		{
			++c;
			if (count & 1)
			{
				++denominator;
				--numerator;
			}

			else
			{
				--denominator;
				++numerator;
			}
		}
	}


	string answer;

	answer += to_string(numerator);
	answer += "/";
	answer += to_string(denominator);

	cout << answer << endl;

	return 0;
}