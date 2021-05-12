#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ALPABET 26

int main()
{
	string s;
	int answer = 0;
	getline(cin, s);

	if (s == " ")
	{
		printf("0");
		return 0;
	}

	for (int i = 0; i < s.length() - 1; ++i)
	{
		if (i != 0 && s[i] == ' ' && s[i + 1] != ' ')
		{
			++answer;
		}
	}

	if (s[s.length() - 1] != ' ' || (s[s.length() - 1] == ' ' && s[s.length() - 2] != ' ')) ++answer;

	printf("%d", answer);

	return 0;
}