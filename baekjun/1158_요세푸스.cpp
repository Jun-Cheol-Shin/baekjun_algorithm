#include <iostream>
using namespace std;
#include <queue>

int main()
{
	int n, k;
	queue<int> q;
	queue<int> temp_q;

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) q.push(i);

	printf("<");

	for(int i = 1; i <= n; ++i)
	{
		int count = 1;

		while (count != k)
		{
			++count;
			if (q.size()) 
			{
				temp_q.push(q.front());
				q.pop();
			}
			else
			{
				int val = temp_q.front();
				temp_q.pop();
				temp_q.push(val);
			}
		}

		while (temp_q.size())
		{
			q.push(temp_q.front());
			temp_q.pop();
		}

		printf("%d", q.front());
		q.pop();

		if (q.size() != 0) printf(", ");
	}

	printf(">\n");
}