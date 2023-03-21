#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int cnt = 0;
vector<pair<int,bool>> friends[501];
bool visited[501];


void reset() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1 || b == 1) {
			friends[a].push_back({ b,true });
			friends[b].push_back({ a,true });
		}
		else {
			friends[a].push_back({ b,false });
			friends[b].push_back({ a,false });
		}
	}
}

void solution() {
	queue<pair<int,bool>> q;
	q.push({ 1,true });
	visited[1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		bool tf = q.front().second;
		q.pop();
		if (tf == true) {
			for (int i = 0; i < friends[x].size(); i++) {
				if (visited[friends[x][i].first] == true)continue;
				visited[friends[x][i].first] = true;
				q.push(friends[x][i]);
				cnt++;
			}
		}
	}
	cout << cnt;
}

void solve() {
	input();
	reset();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();


	return 0;
}