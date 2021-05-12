#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	* 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

	둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

	예제:
	5
	5 50 50 70 80 100
	7 100 95 90 80 70 60 50
	3 70 90 80
	3 70 90 81
	9 100 99 98 97 96 95 94 93 91

	출력:
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