#include <iostream>
#include <queue>
using namespace std;

// 2초에 2배
// 1초에 -1개

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

			// 클립보드 복사
			q.push({ curr, curr });

			// 붙여넣기
			if (!visited[curr + clip][clip] && curr + clip < LIMIT && clip > 0)
			{
				q.push({ curr + clip, clip });
				visited[curr + clip][clip] = true;
			}

			// 하나 지우기
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

	// 기본 : 1 0
	// 붙여넣기 : 2 2
	// 2개 붙여넣기 4 4
	// 2개 붙여넣기 6 5

	solved(s);

	return 0;
}