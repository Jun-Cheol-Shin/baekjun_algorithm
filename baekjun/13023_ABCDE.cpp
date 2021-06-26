#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 2000 + 1

int n, m;
bool visit[MAX], answer = 0;
vector<int> v[MAX];

void dfs(int idx, int cnt) {
	if (cnt == 4) {
		answer = true;
		return;
	}

	visit[idx] = true;
	for (int i = 0; i < v[idx].size(); i++) {
		int n_idx = v[idx][i];
		if (visit[n_idx] == false) {
			dfs(n_idx, cnt + 1);
		}
		if (answer == true) return;
	}
	visit[idx] = false;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, 0);
		if (answer == true) break;
	}

	cout << answer << "\n";

	return 0;
}