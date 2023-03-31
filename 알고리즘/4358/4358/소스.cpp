#include <iostream>
#include <string>	
#include <map>
#include <algorithm>

using namespace std;
map<string, float> m;
float cnt, result;

void input() {
	string str;
	while (getline(cin, str)) {
		cnt++;
		if (m.find(str) != m.end()) {
			m[str] ++;
		}
		else {
			m[str] = 1;
		}
	}
}


void solution() {
	cout << fixed;
	cout.precision(4);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		result = (iter->second / cnt) * 100;
		cout << iter->first << " " << result << "\n";
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	solve();

	return 0;
}