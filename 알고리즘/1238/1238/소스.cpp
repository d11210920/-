#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n, m, x;
vector<pair<int,int>> road[1001];
int dp[1001];
bool visited[1001];

void input() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
	}
}

void reset() {
	for (int i = 0; i <= n; i++) {
		dp[i] = MAX;
		visited[i] = false;
	}
}

void dijkstra(int idx) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -road[idx].front().second, {idx,road[idx].front().first } });
	dp[idx] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int start = pq.top().second.first;
		int arrive = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < road[start].size(); i++) {
			if (dp[arrive] > cost + road[start][i].second) {
				dp[arrive] = cost + road[start][i].second;
				if (arrive == x)return;
				pq.push({ -dp[arrive],{start,road[start][i].first} });
			}
		}
	}
}


void solve() {
	input();
	int max = 0;
	int max_idx = 0;
	reset();
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		if (max < dp[x]) {
			max = dp[x];
			max_idx = i;
		}
		reset();
	}
	cout << max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();



	return 0;
}