#include <iostream>
#include <queue>	
#include <vector>
#include <string>

using namespace std;

string map[8];
bool succ = false;
int dx[9] = { 1,1,0,-1,-1,-1,0,1,0 };
int dy[9] = { 0,-1,-1,-1,0,1,1,1,0 };

void input() {
	for (int i = 7; i >= 0; i--) {
		cin >> map[i];
	}
}

void solution() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == 7) {
				succ = true;
				return;
			}
			for (int i = 0; i < 9; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx > 7 || nx < 0 || ny > 7 || ny < 0)continue;
				if (map[nx][ny] == '#')continue;
				if (nx + 1 < 8 && map[nx + 1][ny] == '#') continue;
				q.push({ nx,ny });
			}
		}
		for (int i = 0; i < 7; i++) {
			map[i] = map[i + 1];
		}
		map[7] = "........";
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	if (succ)cout << 1;
	else cout << 0;


	return 0;
}