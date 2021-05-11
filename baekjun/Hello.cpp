#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 곱셈 3, 4, 5, 6 출력
int main(void) {
	int a;
	string b;
	vector<int> vec;

	cin >> a >> b;

	for (int i = b.length() - 1; i >= 0; --i)
	{
		int c = b[i] - '0';
		vec.push_back(a * c);
	}

	vec.push_back(a * stoi(b));

	for (int i = 0; i < vec.size(); ++i)
	{
		printf("%d\n", vec[i]);
	}


	return 0;
}