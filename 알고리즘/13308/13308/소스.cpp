#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

long long int dp[2501][2501];
int gasStation[2501];
int n, m;
int cost;

vector <pair<int, int>> road[2501];
priority_queue<pair<long long int, pair<int, int>>> pq;

void input() {
	int a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> gasStation[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		road[a].push_back(make_pair(b, cost));
		road[b].push_back(make_pair(a, cost));
	}
}

void dijkstra() {
	int here, there, here_o, there_o;
	long long int here_c, there_c;
	long long int min_c;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 2501; j++)
			dp[i][j] = -1;
	pq.push(make_pair(0, make_pair(1, gasStation[1])));

	while (!pq.empty()) {
		here = pq.top().second.first;
		here_c = -pq.top().first;
		here_o = pq.top().second.second;
		pq.pop();

		if (dp[here][here_o] != -1)
			continue;

		dp[here][here_o] = here_c;

		if (here == n) {
			min_c = here_c;
			break;
		}
		for (int i = 0; i < road[here].size(); i++) {
			there = road[here][i].first;
			there_c = road[here][i].second * min(here_o, gasStation[here]) + here_c;
			there_o = min(here_o, gasStation[here]);


			if (dp[there][there_o] == -1) {
				pq.push(make_pair(-there_c, make_pair(there, there_o)));
			}
		}

	}
	cout << min_c;
}

void solve() {
	input();
	dijkstra();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();


	return 0;
}