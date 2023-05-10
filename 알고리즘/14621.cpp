#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
int cnt = 1;
char university[1001];
vector<pair<int,pair<int,int>>> edge;
int parent[1001];
int n,m;

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> university[i];
        parent[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int x,y,d;
        cin >> x >> y >> d;
        edge.push_back({d,{x,y}});
    }
    sort(edge.begin(), edge.end());
}

int getParent(int x){
    if(x == parent[x]) return x;
    else return parent[x] = getParent(parent[x]);
}

bool findParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if(x == y) return true;
    else return false;
}

void unionParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

void Kruskal(){
    for(int i = 0; i < edge.size(); i++){
        int x = edge[i].second.first;
        int y = edge[i].second.second;
        int d = edge[i].first;
        if(university[x] != university[y] && findParent(x,y) == false){
            unionParent(x,y);
            ans += d;
            cnt++;
        }
    }
}

void solve(){
    input();
    Kruskal();
    if(cnt == n) cout << ans;
    else cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}