#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 987654321

using namespace std;
int area[101];
int distance_[101];
vector<pair<int, int>> edge[101];
int n, m, r;
int a, b, l;
int max_res = 0;
int item = 0;

void dijkstra(int idx) {
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		distance_[i] = MAX;
	}
	distance_[idx] = 0;
	q.push(idx);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int dist = distance_[x];

		for (int i = 0; i < edge[x].size(); i++) {
			int next_x = edge[x][i].first;
			int next_dist = edge[x][i].second;

			if (distance_[next_x] > dist + next_dist) {
				distance_[next_x] = dist + next_dist;
				q.push(next_x);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (distance_[i] <= m)cnt += area[i];
	}
	max_res = max(max_res, cnt);
}


int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> area[i];
	}
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		edge[a].push_back({ b,l });
		edge[b].push_back({ a,l });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	cout << max_res;
	return 0;
}