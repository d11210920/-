#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;
bool visited[11][31];

int N, M, H;
bool success();
void play(int, int);
int res = MAX;
int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		visited[b][a] = true;
	}
	play(1, 0);
	if (res == MAX) cout << -1;
	else cout << res;

	return 0;
}

bool success() {
	for (int i = 1; i <= N; i++) {
		int curr = i;
		for (int j = 1; j <= H; j++) {
			if (visited[curr][j] == true)curr++;
			else if (visited[curr - 1][j] == true)curr--;
		}
		if (curr != i)return false;
	}
	return true;
}


void play(int idx, int cnt) {
	if (cnt > 3) return;
	if (success() == true) {
		res = min(res, cnt);
		return;
	}
	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (visited[j][i] == true)continue;
			if (visited[j + 1][i] == true)continue;
			if (visited[j - 1][i] == true)continue;

			visited[j][i] = true;
			play(i, cnt + 1);
			visited[j][i] = false;
		}
	}
}