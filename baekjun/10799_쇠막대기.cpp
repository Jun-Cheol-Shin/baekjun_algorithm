#include <iostream>
using namespace std;
#include <string>
#include <stack>

int main()
{
	string _steel = "";
	cin >> _steel;

	stack<char> _stack;

	int answer = 0;


	for (int i = 0; i < _steel.length(); ++i)
	{
		if (_steel[i] == '(')
		{
			_stack.push(_steel[i]);
		}

		else if (_steel[i] == ')')
		{
			_stack.pop();
			if (_steel[i - 1] == '(')
			{
				answer += _stack.size();
			}
			else
			{
				++answer;
			}
		}
	}

	cout << answer << endl;

}
