#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

int main()
{
	// 2차원 배열 DP 활용
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int vec[1001][4];

	// 입력 받기
	for (int i = 1; i <= n; ++i) cin >> vec[i][1] >> vec[i][2] >> vec[i][3];


	// i는 목표 값 j는 j번째 값으로 끝났을 경우
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			switch (j)
			{
			case 1:
				vec[i][j] = min(vec[i - 1][2] + vec[i][1], vec[i - 1][3] + vec[i][1]);
				break;
			case 2:
				vec[i][j] = min(vec[i - 1][1] + vec[i][2], vec[i - 1][3] + vec[i][2]);
				break;
			case 3:
				vec[i][j] = min(vec[i - 1][1] + vec[i][3], vec[i - 1][2] + vec[i][3]);
				break;
			}
		}
	}

	// 최소값 출력
	cout << min(min(vec[n][1], vec[n][2]), vec[n][3]) << "\n";

}