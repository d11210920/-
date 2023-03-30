#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
int visited[2010];
bool answer = true;
vector<int> enemy[2010];

void input() {
	memset(visited, -1, sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		enemy[x].push_back(y);
		enemy[y].push_back(x);
	}
}

void dfs(int curr) {
	for (int i = 0; i < enemy[curr].size(); i++) {
		int next = enemy[curr][i];
		if (visited[next] == -1) {
			if (visited[curr] == 1) visited[next] = 0;
			else visited[next] = 1;
			dfs(next);
		}
		else if (visited[next] == visited[curr]) answer = false;
	}
}

void solve() {
	input();
	for (int i = 1; i <= n; i++) {
		if (visited[i] == -1) {
			visited[i] = 1;
			dfs(i);
		}
	}
	cout << answer << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}