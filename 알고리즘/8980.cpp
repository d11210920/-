#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,pair<int,int>>> v;
int capacity[10001] = {0,};
int n,c,m;
int ans = 0;

void input(){
    cin >> n >> c >> m;
    for(int i = 0; i < m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        v.push_back({y,{x,z}});
    }
}

void solution(){
    for(int i = 0; i < m; i++){
        int curr_cnt = 0;
        for(int j = v[i].second.first; j < v[i].first; j++){
            curr_cnt = max(curr_cnt,capacity[j]);
        }
        int tmp = min(v[i].second.second, c - curr_cnt);
        ans += tmp;
        for(int j = v[i].second.first; j < v[i].first; j++){
            capacity[j] += tmp;
        }
    }
}

void solve(){
    input();
    sort(v.begin(), v.end());
    solution();
    cout << ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}