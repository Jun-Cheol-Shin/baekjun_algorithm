#include <iostream>
using namespace std;


int main()
{
	int A, B, V;
	int answer;
	cin >> A >> B >> V;

	if (((V - B) % (A - B)) & 1)
	{
		answer = (V - B) / (A - B) + 1;
	}
	else
	{
		answer = (V - B) / (A - B);
	}


	printf("%d", answer);

	return 0;
}