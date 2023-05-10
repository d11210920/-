#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define ld long double

using namespace std;

ld ans = 0;
int n,m;
int cnt = 1;

vector<pair<int,int>> gods;
vector<pair<ld,pair<int,int>>> edge;
int parent[1001];

int getParent(int x){
    if(x == parent[x]) return x;
    else return getParent(parent[x]);
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
    cnt++;
}



void input(){
    cin >> n >> m;
    gods.push_back({0,0});
    for(int i = 1; i <= n; i++){
        int x,y;
        cin >> x >> y;
        gods.push_back({x,y});
        ld distance;
        for(int j = 1; j < gods.size()-1; j++){
            distance = sqrt(pow((x-gods[j].first),2) + pow((y-gods[j].second),2));
            edge.push_back({distance,{j,i}});
        }
        parent[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        if(!findParent(x,y)){
            unionParent(x,y);
        }
    }
}

void solve(){
    input();
    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        if(cnt==n)break;
        int x = edge[i].second.first;
        int y = edge[i].second.second;
        ld dist = edge[i].first;

        if(!findParent(x,y)){
            unionParent(x,y);
            ans += dist;
        }
    }
    cout << setprecision(2) << fixed << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}