#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

long long dp[10001];
int n;


int main() {
	dp[0] = 1;
	dp[1] = 1;
	cin >> n;
	for (int i = 1; i <= n / 2; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			dp[i] += ((dp[j] % INF)*(dp[i - j - 1] % INF) % INF);
		}
	}
	cout << dp[n / 2] % INF;


	return 0;
}
