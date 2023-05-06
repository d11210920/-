#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int n,m;
vector<int> v[101];
priority_queue<int> pq;
int sum = 0;

void solution(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int p,l;
        cin >> p >> l;
        for(int j = 0; j < p; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        if(p <= l) {
            sum++;
            pq.push(1);
            if(sum > m){
                sum -= pq.top();
                pq.pop();
            }
        }
        else {
            sort(v[i].begin(), v[i].end(), greater<>());
            pq.push(v[i][l - 1]);
            sum += v[i][l - 1];
            if (sum > m) {
                sum -= pq.top();
                pq.pop();
            }
        }
    }
    cout << pq.size();
}

int main(){
    solution();
    return 0;
}