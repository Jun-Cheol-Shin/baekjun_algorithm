#include <iostream>
#include <vector>
using namespace std;
#define MAX 27

void preOrder(const vector<vector<char>>& vec, char root)
{
	if (root == '.') return;

	cout << root;
	preOrder(vec, vec[root - 'A'][0]);
	preOrder(vec, vec[root - 'A'][1]);
}

void inOrder(const vector<vector<char>>& vec, char root)
{
	if (root == '.') return;

	inOrder(vec, vec[root - 'A'][0]);
	cout << root;
	inOrder(vec, vec[root - 'A'][1]);
}

void postOrder(const vector<vector<char>>& vec, char root)
{
	if (root == '.') return;

	postOrder(vec, vec[root - 'A'][0]);
	postOrder(vec, vec[root - 'A'][1]);
	cout << root;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<char>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		char root, l, r;
		cin >> root >> l >> r;

		vec[root - 'A'].push_back(l);
		vec[root - 'A'].push_back(r);
	}

	preOrder(vec, 'A');
	cout << "\n";
	inOrder(vec, 'A');
	cout << "\n";
	postOrder(vec, 'A');

	return 0;
}