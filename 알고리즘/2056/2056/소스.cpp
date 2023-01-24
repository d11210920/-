#include <iostream>
#include <vector>	
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
vector<int> sequence[10001];
int work[10003];
int work_c[10003];
int degree[10003];
int time = 0;

void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) q.push(i);
	}
	
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (int i = 0; i < sequence[idx].size(); i++) {
			int tmp = sequence[idx][i];
			work_c[tmp] = max(work_c[tmp], work_c[idx] + work[tmp]);
			degree[tmp]--;
			if (degree[tmp] == 0) q.push(tmp);
		}
	}
}



int main() {
	cin >> n;
	memset(degree, 0, n + 1);
	memset(work, 0, n + 1);
	memset(work_c, 0, n + 1);	for (int i = 1; i <= n; i++) {
		int x;
		cin >> work[i] >> x;
		work_c[i] = work[i];
		for (int j = 0; j < x; j++) {
			int y;
			cin >> y;
			sequence[y].push_back(i);
			degree[i]++;
		}
	}
	topologicalSort();
	for (int i = 1; i <= n; i++) {
		time = max(time, work_c[i]);
	}
	cout << time;

	return 0;
}