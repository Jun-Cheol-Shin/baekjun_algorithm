#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// �Է� �ð� ���̱�
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

	// endl���� \n�� �� ������.
	for (int i = 0; i < size; ++i) cout << answer[i] << "\n";

	return 0;
}