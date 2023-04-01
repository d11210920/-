#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321

typedef long long ll;

using namespace std;
int n, m, k;

ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
	if (start == end)return tree[node] = a[start];
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2)
			+ init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

ll findSum(vector<ll> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return findSum(tree, node * 2, start, (start + end) / 2, left, right)
		+ findSum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll newNode) {
	if (index < start || index > end)return;
	tree[node] = tree[node] + newNode;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, newNode);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, newNode);
	}
}

void solve() {
	cin >> n >> m >> k;
	vector<ll> v(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> tree(tree_size);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	init(v, tree, 1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			ll newNode = c - v[b];
			v[b] = c;
			update(tree, 1, 0, n - 1, b, newNode);
		}
		else if (a == 2) {
			cout << findSum(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
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