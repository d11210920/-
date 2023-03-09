#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int leave, arrive;

vector<pair<int, int>> bus[1001];
int dist[1001];	

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back({ b,c });
	}

	cin >> leave >> arrive;
	for (int i = 1; i <= n; i++) {
		dist[i] = 987654321;
	}
}

void dijkstra() {
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,leave });
	dist[leave] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (dist[curr] < cost) continue;

		for (int i = 0; i < bus[curr].size(); i++) {
			int next = bus[curr][i].first;
			int newCost = cost + bus[curr][i].second;
			if (dist[next] > newCost) {
				dist[next] = newCost;
				pq.push({ -newCost,next });
			}
		}
	}
	cout << dist[arrive];
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	dijkstra();



	return 0;
}