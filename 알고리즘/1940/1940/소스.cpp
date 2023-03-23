#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[15001];
int cnt = 0;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	sort(arr, arr + n);
	int st = 0, ed = 1;

	while (st <= ed && ed < n) {
		if (arr[st] + arr[ed] == m) cnt++;
		if (ed == n - 1) {
			st++;
			ed = st + 1;
		}
		else ed++;
	}
}

void solve() {
	input();
	solution();
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();


	return 0;
}