#include <iostream>
#include <queue>
using namespace std;

// 2�ʿ� 2��
// 1�ʿ� -1��

#define MIN 2
#define MAX 1000

#define LIMIT 1001
#define CLIPLIMIT 2001
bool visited[LIMIT][CLIPLIMIT] = { false, };

void solved(int goal)
{
	int answer = 0;

	queue<pair<int,int>> q;
	q.push({ 1, 0 });
	visited[1][0] = true;

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; ++i)
		{
			// 1 0
			// 2 2
			// 3 3
			// 6 5
			// 9 6
			// 18 8
			int curr = q.front().first;
			int clip = q.front().second;

			q.pop();

			if (curr == goal)
			{
				cout << answer << "\n";
				return;
			}

			// Ŭ������ ����
			q.push({ curr, curr });

			// �ٿ��ֱ�
			if (!visited[curr + clip][clip] && curr + clip < LIMIT && clip > 0)
			{
				q.push({ curr + clip, clip });
				visited[curr + clip][clip] = true;
			}

			// �ϳ� �����
			if (!visited[curr - 1][clip] && curr - 1 >= MIN)
			{
				q.push({ curr - 1, clip });
				visited[curr - 1][clip] = true;
			}
		}
		answer++;
	}

}

int main()
{
	int s;
	cin >> s;

	// �⺻ : 1 0
	// �ٿ��ֱ� : 2 2
	// 2�� �ٿ��ֱ� 4 4
	// 2�� �ٿ��ֱ� 6 5

	solved(s);

	return 0;
}