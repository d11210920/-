//12015 가장 긴 증가하는 부분수열 2 문제와 코드 동일

#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000001];
vector<int> dp;

/*
	이분탐색!!
*/

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int binarySearch(int x) {
	int st = 0;
	int ed = dp.size() - 1;

	while (ed > st) {
		int mid = (st + ed) / 2;
		if (dp[mid] >= x) {
			ed = mid;
		}
		else st = mid + 1;
	}
	return ed;
}


void solution() {
	dp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (dp.back() < arr[i])dp.push_back(arr[i]);
		else {
			int idx = binarySearch(arr[i]);
			dp[idx] = arr[i];
		}
	}
}
void solve() {
	input();
	solution();
	cout << dp.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}