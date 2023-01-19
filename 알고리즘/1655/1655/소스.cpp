#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

bool visited[9][9] = { 0, };
int building[9][9] = { 0, };
int n, m;
int n_building[9][9] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;

void bfs() {
	int t_building[9][9] = { 0, };
	memcpy(&t_building, &n_building, sizeof(n_building));
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (t_building[i][j] == 2) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > n || nx <1 || ny > m || ny < 1 || visited[nx][ny] == true)continue;
			if (t_building[nx][ny] == 0) {
				t_building[nx][ny] = 2;
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (t_building[i][j] == 0)cnt++;
		}
	}
	ans = max(ans, cnt);
}

void wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (n_building[i][j] == 0) {
					memset(visited, false, sizeof(visited));
					n_building[i][j] = 1;
					wall(cnt + 1);
					n_building[i][j] = 0;
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> building[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (building[i][j] == 0) {
				memset(visited, false, sizeof(visited));
				memcpy(&n_building, &building, sizeof(building));
				n_building[i][j] = 1;
				wall(1);
				n_building[i][j] = 0;
			}
		}
	}
	cout << ans;


	return 0;
}