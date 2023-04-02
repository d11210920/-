#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define moduler 1000000007
typedef long long ll;
using namespace std;

int n, m, k;

ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	else return tree[node] = (init(a, tree, node * 2, start, (start + end) / 2) * init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % moduler;
}

ll mult(vector<ll> &tree, int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 1;
	if (left <= start && end <= right) return tree[node];
	return mult(tree, node * 2, start, (start + end) / 2, left, right) *mult(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right) % moduler;
}

ll update(vector<ll> &tree, int node, int start, int end, int index, ll newNode) {
	if (index < start || index > end) return tree[node];
	if (start == end) return tree[node] = newNode;
	return tree[node] = update(tree ,node * 2, start, (start + end) / 2, index, newNode)*update(tree ,node * 2 + 1, (start + end) / 2 + 1, end, index, newNode) % moduler;
}

void solve() {
	cin >> n >> m >> k;
	vector<ll> v(n);
	int h = (int)ceil(log2(n));
	int size = (1 <<( h + 1));
	vector<ll> tree(size);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> v[i];
	}
	init(v, tree, 1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			ll temp = v[b];
			v[b] = c;
			update(tree, 1, 0, n - 1, b, c);
		}
		else if (a == 2) {
			cout << mult(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();


	return 0;
}