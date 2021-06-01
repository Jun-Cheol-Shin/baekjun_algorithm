#include <iostream>
using namespace std;
#include <string>

int main()
{
	string temp = "";
	string answer;
	getline(cin, answer);


	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; ++i)
	{
		string command;
		getline(cin, command);

		switch (command[0])
		{
		case 'L':
			if (answer.size() > 0)
			{
				temp.push_back(answer.back());
				answer.pop_back();
			}
			break;
		case 'D':
			if (temp.size() > 0) 
			{
				answer.push_back(temp.back());
				temp.pop_back();
			}
			break;
		case 'P':
			answer.push_back(command[2]);
			break;
		case 'B':
			if (answer.size() > 0)
			{
				answer.pop_back();
			}
			break;
		}

		//cout << answer << endl;
	}

	while (temp.size())
	{
		answer.push_back(temp.back());
		temp.pop_back();
	}

	cout << answer << endl;

}