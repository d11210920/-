#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[201];
bool succ = true;

int findParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);
}
void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x != y) {
		if (x < y) parent[y] = x;
		else parent[x] = y;
	}
}
bool sameParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y) return true;
	else return false;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				unionParent(i, j);
			}
		}
	}
	int x;
	cin >> x;
	x = findParent(x);
	for (int i = 1; i < m; i++) {
		int y;
		cin >> y;
		if (x != findParent(y)) {
			succ = false;
		}
	}


	if (succ)cout << "YES";
	else cout << "NO";

	return 0;
}