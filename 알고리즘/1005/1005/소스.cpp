#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int T, N, K;
vector<int> sequence[1001];
int degree[1001];
int building[1001];
int x, y, w;
int building_c[1001];


void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (i == w) continue;
		else if (degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (int i = 0; i < sequence[idx].size(); i++) {
			building_c[sequence[idx][i]] = max(building_c[sequence[idx][i]], building_c[idx] + building[sequence[idx][i]]);
			degree[sequence[idx][i]]--;
			if (degree[sequence[idx][i]] == 0) q.push(sequence[idx][i]);
		}
	}
	cout << building_c[w] << "\n";
}


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		memset(building_c, 0, N);
		memset(degree, 0, N + 1);
		memset(building, 0, N + 1);
		for (int j = 1; j <= N; j++) {
			cin >> building[j];
			building_c[j] = building[j];
		}
		for (int j = 1; j <= K; j++) {
			cin >> x >> y;
			sequence[x].push_back(y);
			degree[y]++;
		}
		cin >> w;
		topologicalSort();
		for (int j = 1; j <= N; j++) {
			sequence[j].clear();
		}
	}



	return 0;
}