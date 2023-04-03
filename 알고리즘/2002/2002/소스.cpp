#include <iostream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> cars;
int n;
int cnt = 0;
int arr[1001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		cars[str] = i;
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		arr[i] = cars[str];
	}
}

void solution() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				cnt++;
				break;
			}
		}
	}
}

void solve() {
	input();
	solution();
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}