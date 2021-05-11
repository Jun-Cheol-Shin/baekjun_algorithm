#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> answer;

	for (int i = 0; i < 9; ++i)
	{
		int a;
		cin >> a;
		answer.push_back(a);
	}

	cout << *max_element(answer.begin(), answer.end()) << endl;
	cout << (max_element(answer.begin(), answer.end()) - answer.begin()) + 1 << endl;
}