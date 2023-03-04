#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321

using namespace std;

int m, n, l;
int cnt = 0;
vector<int> sand;
vector<pair<int,int>> animal;

int main() {
	cin >> m >> n >> l;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		sand.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		animal.push_back({ x,y });
	}
	for (int i = 0; i < animal.size(); i++) {
		bool succ = false;
		for (int j = 0; j < sand.size(); j++) {
			if (animal[i].first >= sand[j]) {
				if (animal[i].first - sand[j] + animal[i].second <= l) {
					cnt++;
					succ = true;
				}
			}
			else {
				if (sand[j] - animal[i].first + animal[i].second <= l) {
					cnt++;
					succ = true;
				}
			}
			if (succ == true) break;
		}
	}
	cout << cnt;


	return 0;
}