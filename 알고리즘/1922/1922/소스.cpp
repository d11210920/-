#include <iostream>
#include <algorithm>
#include <vector>
int n, m;
int a, b, c;
int ans = 0;
int parent[1001];

using namespace std;

int getParent(int x) {
	if (x == parent[x]) return x;
	else {
		return parent[x] = getParent(parent[x]);
	}	
}
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x != y)parent[x] = y;
}
bool compParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edge(m);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[i] = { c, { a,b } };
	}
	sort(edge.begin(), edge.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;

		if (compParent(a, b) == false) {
			ans += edge[i].first;
			unionParent(a, b);
		}
	}
	cout << ans;
	return 0;
}