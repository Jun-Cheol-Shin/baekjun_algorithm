#include <iostream>
#include <queue>
using namespace std;
#define LIMIT 100001

bool visit[LIMIT] = { false, };

void solved(int start, int goal)
{
	//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;	
	queue<pair<int, int>> q;
	q.push({ start , 0 });

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; ++i)
		{
			int curr = q.front().first;
			int count = q.front().second;
			q.pop();

			if (curr == goal)
			{
				cout << count << "\n";
				return;
			}

			if (curr * 2 < LIMIT && !visit[curr * 2])
			{
				visit[curr * 2] = true;
				q.push({ curr * 2, count });
			}

			if (curr - 1 >= 0 && !visit[curr - 1])
			{
				visit[curr - 1] = true;
				q.push({ curr - 1, count + 1 });
			}

			if (curr + 1 < LIMIT && !visit[curr + 1])
			{
				visit[curr + 1] = true;
				q.push({ curr + 1, count + 1 });
			}

			
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	solved(n, k);

	return 0;
}