#include <iostream>
#include <string>	
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr;
int n, m;
int cnt = 0;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		arr.push_back(str);
	}
}

void solution() {
	sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (binary_search(arr.begin(), arr.end(), str)) cnt++;
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
}