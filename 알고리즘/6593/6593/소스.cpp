#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int min_t = 987654321;
int L, R, C;
char building[31][31][31];
int time[31][31][31] = {};
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
bool visited[31][31][31];
struct st {
	int x;
	int y;
	int z;
	int t;
};


int main() {
	cin >> L >> R >> C;
	while (L != 0 && R != 0 && C != 0) {
		min_t = 987654321;
		queue<st> q;
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				for (int k = 1; k <= C; k++) {
					cin >> building[i][j][k];
					visited[i][j][k] = false;
					if (building[i][j][k] == 'S') {
						visited[i][j][k] == true;
						q.push({ i, j, k, 0 });
					}
				}
			}
		}
		while (!q.empty()) {
			st x = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = dx[i] + x.x;
				int ny = dy[i] + x.y;
				int nz = dz[i] + x.z;
				if (nx <1 || nx > L || ny < 1 || ny > R || nz < 1 || nz > C || visited[nx][ny][nz] == true)continue;
				if (building[nx][ny][nz] == '.') {
					q.push({ nx,ny,nz,x.t + 1 });
					visited[nx][ny][nz] = true;
				}
				else if (building[nx][ny][nz] == 'E')min_t = min(x.t + 1, min_t);
			}
		}
		if (min_t == 987654321) cout << "Trapped!\n";
		else cout << "Escaped in " << min_t << " minute(s).\n";
		cin >> L >> R >> C;
	}


	return 0;
}