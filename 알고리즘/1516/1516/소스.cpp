#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int indegree[501] = {};
vector<int> build[501];
int n;
int time[501] = {};
int tmp_time[501] = {};

void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)q.push(i);
	}
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (int i = 0; i < build[idx].size(); i++) {
			int tmp = build[idx][i];
			tmp_time[tmp] = max(tmp_time[tmp], tmp_time[idx] + time[tmp]);
			indegree[tmp]--;
			if (indegree[tmp] == 0)q.push(tmp);
		}
	}

}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		tmp_time[i] = time[i];
		int x;
		while (cin >> x) {
			if (x == -1) break;
			build[x].push_back(i);
			indegree[i]++;
		}
	}
	topologicalSort();
	for (int i = 1; i <= n; i++) {
		cout << tmp_time[i] << "\n";
	}

	return 0;
}