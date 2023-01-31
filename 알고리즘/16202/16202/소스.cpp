#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int findParent(int);

struct Edge {
	int start, end, value;
};

bool compare(Edge e1, Edge e2) {
	return e1.value < e2.value;
}



int parent[10001];
int res = 0;
vector<Edge> edge;
vector<Edge> edge_tmp;
int cnt = 0;
void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y) return;
	parent[y] = x;
}
int findParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);
}

void Kruskal(int idx) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m - idx; i++) {
		if (findParent(edge[i].start) != findParent(edge[i].end)) {
			res += edge[i].value;

			unionParent(edge[i].start, edge[i].end);
			cnt++;
		}
	}
	if (cnt == n - 1) {
		cout << res << ' ';

		cnt = 0;
		res = 0;
	}
	else cout << "0 ";

	edge_tmp.clear();
	for (int i = 1; i < edge.size(); i++) {
		edge_tmp.push_back(edge[i]);
	}
	edge.clear();
	for (int i = 0; i < edge_tmp.size(); i++) {
		edge.push_back(edge_tmp[i]);
	}
}


int main() {
	cin >> n >> m >> k;


	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		Edge tmp;
		tmp.start = x;
		tmp.end = y;
		tmp.value = i;
		edge.push_back(tmp);
	}
	sort(edge.begin(), edge.end(), compare);
	for (int i = 0; i < k; i++) {
		Kruskal(i);
	}


	return 0;
}