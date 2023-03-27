#include <iostream>	
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll cnt = 0;
ll arr[4001][4];
int n;
vector<ll> A_B;
vector<ll> C_D;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A_B.push_back(arr[i][0] + arr[j][1]);
			C_D.push_back(arr[i][2] + arr[j][3]);
		}
	}
	sort(A_B.begin(), A_B.end());
	sort(C_D.begin(), C_D.end());

	for (int i = 0; i < C_D.size(); i++) {
		int ed = upper_bound(A_B.begin(), A_B.end(), -C_D[i]) - A_B.begin();
		int st = lower_bound(A_B.begin(), A_B.end(), -C_D[i]) - A_B.begin();
		cnt += ed - st;
	}
	cout << cnt;
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}