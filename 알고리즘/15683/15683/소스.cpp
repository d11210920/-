#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321

using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int n, m;
int building[9][9];
vector<pair<int, int> > cctv;
int result = MAX;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> building[i][j];
			if (building[i][j] >= 1 && building[i][j] <= 5) {
				cctv.push_back({ i, j });
			}
		}
	}
}

void do_check(int x, int y, int direction) {
	direction %= 4;
	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		x = nx;
		y = ny;
		if (nx <= 0 || ny <= 0 || nx > n || ny > m)return;
		if (building[nx][ny] == 6) return;
		if (building[nx][ny] != 0) continue;
		building[nx][ny] = '#';
	}
}
void solution(int idx) {
	int cctv_cnt = cctv.size();
	if (idx == cctv_cnt) {
		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (building[i][j] == 0) tmp++;
			}
		}
		result = min(result, tmp);
		return;
	}
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int tmp_build[9][9];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tmp_build[i][j] = building[i][j];
		}
	}
	for (int dir = 0; dir < 4; dir++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				tmp_build[i][j] = building[i][j];
			}
		}

		if (building[x][y] == 1) {
			do_check(x, y, dir);
		}
		else if (building[x][y] == 2) {
			do_check(x, y, dir);
			do_check(x, y, dir + 2);

		}
		else if (building[x][y] == 3) {
			do_check(x, y, dir);
			do_check(x, y, dir + 1);
		}
		else if (building[x][y] == 4) {
			do_check(x, y, dir);
			do_check(x, y, dir + 1);
			do_check(x, y, dir + 2);

		}
		else if (building[x][y] == 5) {
			do_check(x, y, dir);
			do_check(x, y, dir + 1);
			do_check(x, y, dir + 2);
			do_check(x, y, dir + 3);
		}
		solution(idx + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				building[i][j] = tmp_build[i][j];
			}
		}
	}
}

void solve() {
	input();
	solution(0);
	cout << result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}