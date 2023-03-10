#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

pair<int, int> store[101];
pair<int, int> destination;
pair<int, int> home;
bool visited[101];
int n;

void input() {
	cin >> n;
	cin >> home.first >> home.second;
	for (int i = 1; i <= n; i++) {
		cin >> store[i].first >> store[i].second;
	}
	cin >> destination.first >> destination.second;
}

bool solution() {
	queue<pair<int, int>> q;
	q.push({ home.first,home.second });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (abs(x - destination.first) + abs(y - destination.second) <= 1000) return true;
		
		for (int i = 1; i <= n; i++) {
			if (visited[i])continue;
			int dest = (abs(x - store[i].first) + abs(y - store[i].second));
			if (dest <= 1000) {
				visited[i] = true;
				q.push({ store[i].first,store[i].second });
			}
		}
	}
	return false;
}

void solve() {
	input();
	if (solution()) cout << "happy\n";
	else cout << "sad\n";
	memset(visited, false, sizeof(visited));
	memset(store, false, sizeof(store));
}



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}