#include <queue>
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[32001];
int degree[32001];
int n, m;
int a, b;


void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0)q.push(i);
	}
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		cout << idx << " ";

		for (int i = 0; i < graph[idx].size(); i++) {
			degree[graph[idx][i]]--;
			if (degree[graph[idx][i]] == 0)q.push(graph[idx][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}
	topologicalSort();


	return 0;
}