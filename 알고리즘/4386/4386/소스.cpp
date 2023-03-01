#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
double x, y;
vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> edge;
int parent[101];
double result = 0;

int findParent(int x) {
	if (x == parent[x])return x;
	return parent[x] = findParent(parent[x]);
}

bool sameParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y) return true;
	return false;
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x < y) parent[y] = x;
	else if (x > y) parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(false);
	cout.tie(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		stars.push_back({ x,y });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < stars.size(); i++) {
		x = stars[i].first;
		y = stars[i].second;
		for (int j = i + 1; j < stars.size(); j++) {
			double x_ = stars[j].first;
			double y_ = stars[j].second;

			double distance = sqrt(pow(x - x_, 2) + pow(y - y_, 2));
			edge.push_back({ distance,{i + 1,j + 1} });
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++) {
		double distance = edge[i].first;
		int idx1 = edge[i].second.first;
		int idx2 = edge[i].second.second;
		if (!sameParent(idx1, idx2)) {
			unionParent(idx1, idx2);
			result += distance;
		}
	}

	cout << setprecision(2) << fixed << result << "\n";


	return 0;
}