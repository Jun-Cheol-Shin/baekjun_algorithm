#include <iostream>
using namespace std;
#define ALRAM 45

int main()
{
	int hour, min;

	cin >> hour >> min;

	if (min >= ALRAM) {
		min -= ALRAM;
	}

	else
	{
		min += 60;
		min -= ALRAM;
		--hour;

		if (hour < 0) hour = 23;
	}

	cout << hour << " " << min;

	return 0;
}