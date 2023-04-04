#include <iostream>
#include <algorithm>
#define MAX 987654321

using namespace std;

int t;	
int width[7];
int height[7];
int result = MAX;

void input() {
	for(int i = 1; i <= 3; i++){
		cin >> width[i] >> height[i];
		width[i + 3] = height[i];
		height[i + 3] = width[i];
	}
}

void solution() {
	for (int i = 1; i <= 6; i++) {
		for (int j = i; j <= 6; j++) {
			for (int k = 1; k <= 6; k++) {
				if (i % 3 == j % 3 || i % 3 == k % 3 || j % 3 == k % 3)continue;
				int width_sum = width[i] + width[j] + width[k];
				int height_sum = max(max(height[i], height[j]), height[k]);

				result = min(result, width_sum * height_sum);

				width_sum = max(width[i] + width[j], width[k]);
				height_sum = max(height[i], height[j]) + height[k];

				result = min(result, width_sum * height_sum);
			}
		}
	}
	cout << result;
	result = MAX;
}

void solve() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solution();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();


	return 0;
}