#include <iostream>
#include <vector>
#include <queue>	

using namespace std;

int n, m;
vector<int> subject[1001];
int indegree[1001] = {};
int cnt[1001] = {};

void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			cnt[i] = 1;
		}
	}
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (int i = 0; i < subject[idx].size(); i++) {
			int tmp = subject[idx][i];
			indegree[tmp]--;
			if (indegree[tmp] == 0) {
				cnt[tmp] = cnt[idx] + 1;
				q.push(tmp);
			}
		}
	}
}



int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		subject[x].push_back(y);
		indegree[y]++;
	}
	topologicalSort();
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}