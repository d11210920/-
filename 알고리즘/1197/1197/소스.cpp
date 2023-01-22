#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];
int v, e, a, b, c;
int weight = 0;

int FindParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = FindParent(parent[x]);
}

bool SameParent(int x, int y) {
	x = FindParent(x);
	y = FindParent(y);
	if (x == y) return true;
	else return false;
}

void UnionParent(int x, int y) {
	x = FindParent(x);
	y = FindParent(y);
	if (x != y) {
		parent[x] = y;
	}
}

int main() {
	vector<pair<int, pair<int, int>>> edges(100001);
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int x = edges[i].second.first;
		int y = edges[i].second.second;
		if (SameParent(x, y)) continue;
		else {
			weight += edges[i].first;
			UnionParent(x, y);
		}
	}

	cout << weight;
	return 0;
}