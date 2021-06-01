#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>

int main()
{
	vector<int> prob;
	vector<int> vec;
	vector<char> answer;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		prob.push_back(a);
	}

	int count = 0;
	bool flag = false;
	reverse(prob.begin(), prob.end());

	while (prob.size())
	{
		int number = prob.back();
		prob.pop_back();

		if (count < number)
		{
			for (int i = count; i < number; ++i)
			{
				vec.push_back(++count);
				answer.push_back('+');
			}
		}

		while (vec.size() && vec.back() != number)
		{
			vec.pop_back();
			answer.push_back('-');
		}

		if (vec.size() && vec.back() == number)
		{
			vec.pop_back();
			answer.push_back('-');
		}

		else
		{
			prob.push_back(number);
			break;
		}
	}

	if (prob.size() > 0)
	{
		printf("NO");
	}

	else
	{
		for (int i = 0; i < answer.size(); ++i)
		{
			printf("%c\n", answer[i]);
		}
	}
}