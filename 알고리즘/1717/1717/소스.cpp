#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[1000001];

int findParent(int x) {
	if (x == parent[x]) {
		return x;
	}
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
	if (x == y)return true;
	else return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, a, b;
		cin >> x >> a >> b;
		if (x == 0) {
			unionParent(a, b);
		}
		else if (x == 1) {
			if (sameParent(a, b) == true) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}



	return 0;
}