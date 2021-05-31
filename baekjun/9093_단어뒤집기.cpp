#include <iostream>
using namespace std;
#include <string>
#include <vector>

int main()
{
	int N;
	vector<char> Vec;

	cin >> N;
	cin.ignore();
	
	for (int i = 0; i < N; ++i)
	{
		string sentence;
		int c = 0;
		getline(cin, sentence);

		//cout << sentence << sentence.length() << endl;

		while (c <= sentence.length())
		{
			while (c < sentence.length() && sentence[c] != ' ')
			{
				Vec.push_back(sentence[c]);
				++c;
			}

			while (Vec.size())
			{
				char a = Vec.back();
				Vec.pop_back();
				printf("%c", a);
			}

			if (c != sentence.length() - 1)
			{
				printf(" ");
				++c;
			}
		}
		printf("\n");
	}
}