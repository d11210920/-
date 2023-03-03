#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int start, end_;
int n;
int result = 0;
vector<pair<int, int>> point;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	start = -1000000000;
	end_ = -1000000000;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		point.push_back({ x,y });
	}
	sort(point.begin(), point.end());
	for (int i = 0; i < point.size(); i++) {
		if (point[i].first <= end_) end_ = max(end_, point[i].second);
		else {
			result += end_ - start;
			start = point[i].first;
			end_ = point[i].second;
		}
	}
	result += end_ - start;
	cout << result;

	return 0;
}