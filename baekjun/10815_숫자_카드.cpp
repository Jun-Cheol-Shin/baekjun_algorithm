#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n;

	vector<int> card(n);
	for (int i = 0; i < n; ++i) cin >> card[i];

	sort(card.begin(), card.end(), less<int>());

	cin >> m;
	vector<int> compareCard(m);
	for (int i = 0; i < m; ++i) cin >> compareCard[i];


	vector<int>::iterator iter;

	for (int i = 0; i < m; ++i)
	{
		iter = lower_bound(card.begin(), card.end(), compareCard[i]);
		if (iter != card.end() && *iter == compareCard[i]) cout << "1" << " ";
		else cout << "0" << " ";
	}


	return 0;
}