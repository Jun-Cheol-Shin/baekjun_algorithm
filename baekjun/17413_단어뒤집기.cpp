#include <iostream>
using namespace std;
#include <string>
#include <stack>

int main()
{
	string s;
	string answer = "";
	getline(cin, s);

	bool flag = false;
	int c = 0;

	while (c < s.length())
	{
		if (s[c] == '<' && !flag)
		{
			flag = true;
			answer += s[c++];
			//cout << s[c - 1] << endl;
		}

		else if (s[c] == '>' && flag)
		{
			flag = false;
			answer += s[c++];
			//cout << s[c - 1] << endl;
		}

		else if (flag)
		{
			answer += s[c++];
			//cout << s[c - 1] << endl;
		}

		else
		{
			stack<char> _stack;
			int c2 = c;
			while (s[c2] != ' ' && s[c2] != '<' && c2 < s.length())
			{
				//cout << s[c2] << endl;
				_stack.push(s[c2++]);
			}

			while (_stack.size())
			{
				//cout << _stack.top() << endl;
				answer += _stack.top();
				_stack.pop();
			}

			if (c2 < s.length() && s[c2] == ' ')
			{
				answer += ' ';
				c = c2 + 1;
			}
			else
			{
				c = c2;
			}
		}

	}

	cout << answer << endl;
}