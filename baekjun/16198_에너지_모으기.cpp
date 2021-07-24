#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void solved(const vector<int>& vec, int energy, int N)
{
	if (N == 2)
	{
		answer = max(energy, answer);
		return;
	}

	for (int i = 1; i < N - 1; ++i)
	{
		vector<int> tmp;
		for (int j = 0; j < N; ++j)
		{
			if(j != i) tmp.push_back(vec[j]);
		}

		int e = vec[i - 1] * vec[i + 1];

		//cout << "모은 에너지 : " << e << "\n";
		solved(tmp, energy + e, N - 1);
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];
	solved(vec, 0, n);

	cout << answer;

	return 0;
}