#include <iostream>
using namespace std;
#include <vector>

int y_size;
int x_size;
// y,x ¼ø
pair<int, int> tet[19][4] = { {{0,0}, {0,1}, {0,2}, {0,3}},
							 {{0,0}, {1,0}, {2,0}, {3,0}},
							 {{0,0}, {0,1}, {1,0}, {1,1}},
							 {{0,0}, {1,0}, {2,0}, {2,1}},
							 {{0,0}, {0,1}, {0,2},{-1,2}},
							 {{0,0}, {0,1}, {1,1}, {2,1}},
							 {{0,0}, {0,1}, {0,2}, {1,0}},
							 {{0,0}, {1,0}, {1,1}, {2,1}},
							 {{0,0}, {0,1}, {-1,1}, {-1,2}},
							 {{0,0}, {0,1}, {0,2}, {1,1}},
							 {{0,0}, {1,0}, {2,0}, {1,1}},
							 {{0,0}, {0,1}, {0,2}, {-1,1}},
							 {{0,0}, {0,1}, {-1,1}, {1,1}},
							 {{0,0}, {0,1}, {-1,1}, {-2,1}},
							 {{0,0}, {0,1}, {0,2}, {1,2}},
							 {{0,0}, {0,1}, {1,0}, {2,0}},
							 {{0,0}, {1,0}, {1,1}, {1,2}},
							 {{0,0}, {1,0}, {1, -1}, {2, -1}},
							 {{0,0}, {0,1}, {1,1}, {1,2}}, };


bool tPossible(pair<int,int>* t, int y, int x)
{ 
	for (int i = 0; i < 4; ++i)
	{
		if (t[i].first + y < 0 || t[i].first + y >= y_size || t[i].second + x < 0 || t[i].second + x >= x_size)
		{
			return false;
		}
	}

	return true;
}

int getValue(const vector<vector<int>>& vec, pair<int, int>* t, int y, int x)
{
	int retval = 0;

	for (int i = 0; i < 4; ++i)
	{
		int cy = t[i].first + y;
		int cx = t[i].second + x;

		retval += vec[cy][cx];
	}

	return retval;
}

int solved(const vector<vector<int>>& vec)
{
	int answer = 0;

	for (int i = 0; i < y_size; ++i)
	{
		for (int j = 0; j < x_size; ++j)
		{
			for (int k = 0; k < 19; ++k)
			{
				if (tPossible(tet[k], i, j))
				{
					answer = max(answer, getValue(vec, tet[k], i, j));
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> tVec;
	cin >> y_size >> x_size;

	for (int i = 0; i < y_size; ++i)
	{
		vector<int> vec(x_size);
		for (int j = 0; j < x_size; ++j)
		{
			cin >> vec[j];
		}
		tVec.push_back(vec);
	}

	cout << solved(tVec) << endl;
}