#include <iostream>
using namespace std;

int main()
{
	int current = 0;
	int max = 0;

	for (int i = 0; i < 10; ++i)
	{
		int _in, _out;
		cin >> _out >> _in;

		current += _in - _out;

		if (max < current)
		{
			max = current;
		}
	}

	cout << max << "\n";
}