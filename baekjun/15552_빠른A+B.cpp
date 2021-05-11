#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 입력 시간 줄이기
	iostream::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	vector<int> answer;
	int a, b, size;
	cin >> count;

	for (int i = 1; i <= count; ++i)
	{
		cin >> a >> b;

		answer.push_back(a + b);
	}

	size = answer.size();

	// endl보다 \n이 더 빠르다.
	for (int i = 0; i < size; ++i) cout << answer[i] << "\n";

	return 0;
}