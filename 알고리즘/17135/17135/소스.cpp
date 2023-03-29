#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int n, m, d;
int arr[17][17];
int dx[3] = { -1,0,1 };
int dy[3] = { 0,-1,0 };
int ans;
queue<pair<int, int>> q;

void input() {
	cin >> n >> m >> d;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
}

void batch(int x, int y, int z){
	int map_copy[17][17];
	bool check[16][16];
	bool visit[16][16];
	int archer[3] = { x,y,z };
	int pos = n + 1; 
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			map_copy[i][j] = arr[i][j];
			check[i][j] = false;
		}
	}


	while (pos > 1){
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= m; k++)
					visit[j][k] = false;

			q = queue<pair<int, int>>(); 
			int init_x = archer[i];
			int init_y = pos - 1;

			q.push({ init_x, init_y });

			while (!q.empty()){
				int now_x = q.front().first;
				int now_y = q.front().second;
				q.pop();

				visit[now_y][now_x] = true; 

				if (map_copy[now_y][now_x] == 1) {
					check[now_y][now_x] = true; 
					break;
				}

				for (int j = 0; j < 3; j++) {
					int next_x = now_x + dx[j];
					int next_y = now_y + dy[j];
					if (next_x >= 1 && next_x <= m && next_y >= 1 && next_y <= n) {
						if ((abs(archer[i] - next_x) + abs(pos - next_y) <= d)) {
							if (!visit[next_y][next_x]) {
								q.push({ next_x, next_y });
							}
						}
					}

				}
			}

		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (check[i][j]) {
					map_copy[i][j] = 0;
				}
			}
		}

		pos--;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j]) cnt++;
		}
	}
	ans = max(ans, cnt);
}

void solve() {
	input();

	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			for (int k = j + 1; k <= m; k++) {
				batch(i, j, k);
			}
		}
	}

	cout << ans << '\n';

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

}