#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	* ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.

	��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)�� ù ���� �־�����, �̾ N���� ������ �־�����. ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

	����:
	5
	5 50 50 70 80 100
	7 100 95 90 80 70 60 50
	3 70 90 80
	3 70 90 81
	9 100 99 98 97 96 95 94 93 91

	���:
	40.000%
	57.143%
	33.333%
	66.667%
	55.556%
*/

int main()
{
	iostream::sync_with_stdio(false);
	cin.tie(NULL);

	int C;
	cin >> C;

	vector<double> answer;

	for (int i = 0; i < C; ++i)
	{
		int sum = 0;
		int N;
		vector<int> scores;
		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			int score;
			cin >> score;
			scores.push_back(score);
			sum += score;
		}

		sum /= N;

		double count = 0;
		for (int j = 0; j < N; ++j)
		{
			if (scores[j] > sum) ++count;
		}

		answer.push_back((double)count / N * 100);
	}

	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < (signed)answer.size(); ++i)
	{
		cout << answer[i] << "%" << "\n";
	}


	return 0;
}