#include <iostream>
#include <algorithm>
using namespace std;
int t, n, m;
int arrA[20001];
int arrB[20001];
int cnt = 0;

void reset() {
	for (int i = 0; i < n; i++) {
		arrA[i] = 0;
	}
	cnt = 0;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}
}

int search(int x) {
	for (int i = 0; i < n; i++) {
		if (arrA[i] > x)return  i;
	}
	return n;
}

void solution() {
	sort(arrA, arrA + n);
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int tmp = search(x);
		cnt += n - tmp;
	}
}

void solve() {
	while (t--) {
		input();
		solution();
		cout << cnt << "\n";
		reset();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	solve();


	return 0;
}