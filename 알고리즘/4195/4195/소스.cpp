#include <iostream>
#include <string>
#include <map>
using namespace std;

int t, cnt, f;

int parent[200001];
int friend_cnt[200001];
map<string, int> m;

int findParent(int x) {
	if (parent[x] == x)return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x < y) {
		parent[y] = x;
		friend_cnt[x] += friend_cnt[y];
	}
	else if (x > y) {
		parent[x] = y;
		friend_cnt[y] += friend_cnt[x];
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str1, str2;
	map<string, int>::iterator iter;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> f;
		int a, b;
		m.clear();
		cnt = 0;
		for (int j = 0; j < 200001; j++) {
			parent[j] = j;
			friend_cnt[j] = 1;
		}
		for (int j = 0; j < f; j++) {
			cin >> str1 >> str2;
			iter = m.find(str1);
			if (iter == m.end()) {
				m[str1] = ++cnt;
				a = cnt;
			}
			else a = iter->second;
			iter = m.find(str2);
			if (iter == m.end()) {
				m[str2] = ++cnt;
				b = cnt;
			}
			else b = iter->second;
			unionParent(a, b);
			int root = findParent(a);
			cout << friend_cnt[findParent(root)] << "\n";
		}
	}
	return 0;
}