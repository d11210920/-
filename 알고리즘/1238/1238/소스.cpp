#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n, m, x;
vector<pair<int,int>> road[1001];
int dp[1001];
int tmp[1001];

void input() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
	}
}

void reset() {
	for (int i = 1; i <= n; i++) {
		dp[i] = MAX;
	}
}

void dijkstra(int idx) {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0, idx });
	dp[idx] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < road[cur].size(); i++) {
			int next = road[cur][i].first;
			int newCost = cost + road[cur][i].second;

			if (dp[next] > newCost) {
				dp[next] = newCost;
				pq.push({ -dp[next],next });
			}
		}
	}
}


void solve() {
	input();
	for (int i = 1; i <= n; i++) {
		reset();
		dijkstra(i);
		tmp[i] = dp[x];
	}
	reset();
	dijkstra(x);
	for (int i = 1; i <= n; i++)tmp[i] += dp[i];
	sort(tmp + 1, tmp + n + 1);
	cout << tmp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();



	return 0;
}