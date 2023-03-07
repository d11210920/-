#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, k;
queue<int> person[22];
string student[400000];
long long cnt = 0;

void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> student[i];
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		int length = student[i].size();
		while (!person[length].empty() && i - person[length].front() > k) {
			person[length].pop();
		}
		cnt += person[length].size();
		person[length].push(i);
	}
	cout << cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();



	return 0;
}