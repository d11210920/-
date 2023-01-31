#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int indegree[1001] = {};
vector<int> singer[1001];
vector<int> res;

void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		res.push_back(idx);
		for (int i = 0; i < singer[idx].size(); i++) {
			int next_idx = singer[idx][i];
			indegree[next_idx]--;

			if (indegree[next_idx] == 0) q.push(next_idx);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		vector<int> tmp;
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int x;
			cin >> x;
			tmp.push_back(x);
		}
		for (int j = 0; j < tmp.size(); j++) {
			for (int k = j + 1; k < tmp.size(); k++) {
				singer[tmp[j]].push_back(tmp[k]);
				indegree[tmp[k]]++;
			}
		}
	}
	topologicalSort();
	if (res.size() != n)cout << 0;
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << "\n";
		}
	}

	return 0;
}