#include <iostream>
#include <string>
using namespace std;

/*	
	� ���� ���� X�� �� �ڸ��� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�. 
	���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�. 
	N�� �־����� ��, 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
*/

bool han(int X);

int main()
{
	int N;
	cin >> N;

	int answer = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (han(i)) ++answer;
	}

	printf("%d", answer);

	return 0;
}

bool han(int X)
{
	if (X < 100) return true;

	else
	{
		string number = to_string(X);
		int comp = (number[0] - '0') - (number[1] - '0');

		for (int i = 1; i < number.length() - 1; ++i)
		{
			if (comp != (number[i] - '0') - (number[i + 1] - '0'))
			{
				return false;
			}
		}
	}

	return true;
}