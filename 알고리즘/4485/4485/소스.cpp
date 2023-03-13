#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int t, n;
int cave[126][126];
bool visited[126][126];
int dp[126][126];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input() {
	cin >> n;
	if (n == 0) return;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cave[i][j];
			visited[i][j] = false;
			dp[i][j] = INF;
		}
	}
}
void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	visited[0][0] = true;
	dp[0][0] = cave[0][0];
	pq.push({ -dp[0][0],{0, 0} });
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= n || nx < 0 || ny >= n || ny < 0 || visited[nx][ny] == true)continue;
			int newCost = cost + cave[nx][ny];
			if (nx == n - 1 && ny == n - 1) {
				dp[nx][ny] = min(dp[nx][ny], newCost);
				return;
			}
			else {
				if (dp[nx][ny] > newCost) {
					dp[nx][ny] = newCost;
					pq.push({ -newCost,{nx,ny} });
					visited[nx][ny] = true;
				}
			}
		}
	}
}


void solve() {
	int cnt = 1;
	while (true) {
		input();
		if (n == 0)break;
		dijkstra();
		cout << "Problem " << cnt << ": " << dp[n - 1][n - 1] << "\n";
		cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();



	return 0;
}