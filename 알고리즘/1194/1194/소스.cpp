#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 987654321
using namespace std;
int n, m;
char miro[51][51];
bool visited[51][51][1 << 6];
int dx[4] = { 1,-1,0,0 };
pair<int, int> start;
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> ex;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			miro[i][j] = str[j - 1];
			visited[i][j][0] = false;
			if (miro[i][j] == '0') { 
				start = { i,j }; 
				miro[i][j] = '.';
			}
			if (miro[i][j] == '1') ex.push_back({ i,j });
		}
	}
}

bool haveKeys(int keys, char door) {
	int trueFalse = keys & (1 << (int(door) - 'A'));
	if (trueFalse != 0) return true;
	return false;
}

int bfs() {
	queue<pair<pair<int, int>,pair<int,int>>> q;
	q.push({ start, { 0,0 } });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int keys = q.front().second.second;
		int cnt = q.front().second.first;
		q.pop();
		if (miro[x][y] == '1') return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (visited[nx][ny][keys] == true || nx <1 || nx > n || ny < 1 || ny > m) continue;
			if (miro[nx][ny] == '1' || miro[nx][ny] == '.') {
				visited[nx][ny][keys] = true;
				q.push({ {nx,ny},{cnt + 1,keys} });
			}
			else if ('a' <= miro[nx][ny] && miro[nx][ny] <= 'f') {
				int tmpKey = keys | (1 << (int(miro[nx][ny] - 'a')));
				visited[nx][ny][tmpKey] = true;
				q.push({ {nx,ny},{cnt + 1,tmpKey} });
			}
			else if ('A' <= miro[nx][ny] && miro[nx][ny] <= 'F') {
				if (haveKeys(keys, miro[nx][ny]) == true) {
					visited[nx][ny][keys] = true;
					q.push({ {nx,ny},{cnt + 1,keys} });
				}
			}
			
		}
	}
	return -1;
}


void solution() {
	input();
	int result = bfs();
	cout << result;
}






int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solution();

	return 0;
}