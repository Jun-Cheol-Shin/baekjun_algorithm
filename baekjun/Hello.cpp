#include <iostream>
#include <string>
#include <vector>
using namespace std;

//	문제 : (1)과 (2)위치에 들어갈 세 자리 자연수가 주어질 때 (3), (4), (5), (6)위치에 들어갈 값을 구하는 프로그램을 작성하시오.
//	입력 : 첫째 줄에(1)의 위치에 들어갈 세 자리 자연수가, 둘째 줄에(2)의 위치에 들어갈 세자리 자연수가 주어진다.
//	출력 : 첫째 줄부터 넷째 줄까지 차례대로 (3), (4), (5), (6)에 들어갈 값을 출력한다.

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