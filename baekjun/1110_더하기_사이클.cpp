#include <iostream>
#include <string>
using namespace std;

int main()
{
	int answer = 0;
	string N, temp, first;

	cin >> N;
	if (N.length() < 2) N.insert(N.begin(), '0');

	first = N;
	string c;

	//cout << first << endl;

	while (1)
	{
		temp = "";
		++answer;
												// N = 26
		temp += N[1];							// 6
		int b = (N[0] - '0') + (N[1] - '0');	// 2 + 6

		c = to_string(b);

		b > 9 ? temp += c[1] : temp += c;

		//cout << temp << endl;

		if (temp == first) break;
		N = temp;

		//cout << endl;
	}


	printf("%d", answer);

	return 0;
}