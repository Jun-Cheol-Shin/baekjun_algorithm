#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check[10];

bool func(string left, string right) 
{
	return left.length() < right.length();
}

int main()
{
	int n;
	cin >> n;

	vector<string> vec(n);
	vector<int> alphabet(26, 0);
	for (int i = 0; i < n; ++i)	cin >> vec[i];
	sort(vec.begin(), vec.end(), func);


	for (int i = 0; i < n; ++i)
	{
		reverse(vec[i].begin(), vec[i].end());
		for (int j = vec[i].length() - 1; j >= 0; --j)	alphabet[vec[i][j] - 'A'] += pow(10, j);
	}

	sort(alphabet.begin(), alphabet.end(), greater<int>());

	int answer = 0;
	int count = 9;

	for (int i = 0; i < 26; ++i)
	{
		if (alphabet[i] > 0) answer += (alphabet[i] * count--);
	}

	cout << answer;


	return 0;
}