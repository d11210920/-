#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

int n, e;
int need_1, need_2;
vector<pair<int, int>> edge[200001];
long long dist[801];

void input() {
	cin >> n >> e;
	int x, y, dist_;
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> dist_;
		edge[x].push_back({ y,dist_ });
		edge[y].push_back({ x,dist_ });
	}
	cin >> need_1 >> need_2;
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
}

void dijkstra(int k) {
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,k });
	dist[k] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if (dist[idx] < cost)continue;
		for (int i = 0; i < edge[idx].size(); i++) {
			int next = edge[idx][i].first;
			long long next_cost = cost + edge[idx][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ -next_cost,next });
			}
		}
	}
}

void solve() {
	input();
	dijkstra(1);
	long long tmpNeed1 = dist[need_1];
	long long tmpNeed2 = dist[need_2];
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
	dijkstra(need_1);
	tmpNeed1 += dist[need_2];
	tmpNeed2 += dist[n];
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
	dijkstra(need_2);
	tmpNeed1 += dist[n];
	tmpNeed2 += dist[need_1];

	if (min(tmpNeed1, tmpNeed2) < MAX) { 
		cout << min(tmpNeed1, tmpNeed2); 
	}
	else cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
