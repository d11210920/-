#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

#define MAX 987654321
using namespace std;

int n, m;
queue<pair<int,int>> q;
int arr[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt[101][101];

void dfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (arr[nx][ny] == 0) {
				if (cnt[nx][ny] > cnt[x][y]) {
					cnt[nx][ny] = cnt[x][y];
					q.push({ nx,ny });
				}
			}
			else if (arr[nx][ny] == 1) {
				if (cnt[nx][ny] > cnt[x][y] + 1) {
					cnt[nx][ny] = cnt[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			
		}

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[j + 1][i] = str[j] - '0';
			cnt[j + 1][i] = MAX;
		}
	}
	cnt[1][1] = 0;
	q.push({ 1,1 });
	dfs();
	cout << cnt[n][m];


	return 0;
}