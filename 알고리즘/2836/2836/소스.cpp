#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long result = 0;
vector<pair<int, int>> person;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y)person.push_back({ x,y });
	}

}

void solve() {
	sort(person.begin(), person.end(), compare);
	int start = -1, end_ = -1;
	result += m;

	for (int i = 0; i < person.size(); i++) {
		int from = person[i].first;
		int to = person[i].second;
		
		if (start == -1 && end_ == -1) {
			start = from;
			end_ = to;
		}
		else {
			if (from >= end_) {
				end_ = min(end_, to);
			}
			else {
				result += 2 * (start - end_);

				start = from;
				end_ = to;
			}
		}
	}
	result += 2 * (start - end_);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	cout << result;






	return 0;
}