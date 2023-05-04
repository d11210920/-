#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> cost;
int result;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        cost.push_back(make_pair(d, p));
    }

    sort(cost.begin(), cost.end());

    for (int i = 0; i < n; i++) {
        pq.push(cost[i].second);
        result += cost[i].second;

        if (pq.size() > cost[i].first) {
            result -= pq.top();
            pq.pop();
        }
    }

    cout << result;
    return 0;
}
