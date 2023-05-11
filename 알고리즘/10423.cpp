#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
int n, m, k;
vector<int> plant;
vector<pair<int,pair<int,int>>> edge;
int parent[1001];

void input(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        plant.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        edge.push_back({z,{x,y}});
    }

}

int getParent(int x){
    if(x == parent[x]) return x;
    else return getParent(parent[x]);
}

bool findParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if( x == y) return true;
    else return false;
}

bool isInPlant(int x){
    for(int i = 0; i < plant.size(); i++){
        if(x == plant[i]) return true;
    }
    return false;
}

void unionParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if(isInPlant(x)){
        parent[y] = x;
    }
    else if(isInPlant(y)){
        parent[x] = y;
    }
    else {
        if (x < y)parent[y] = x;
        else parent[x] = y;
    }
}


void solve(){
    input();
    sort(edge.begin(),edge.end());
    for(int i = 0; i < edge.size(); i++){
        int x = edge[i].second.first;
        int y = edge[i].second.second;
        int z = edge[i].first;
        if(!findParent(x,y) && !(isInPlant(getParent(x)) && isInPlant(getParent(y)))){
            unionParent(x,y);
            ans += z;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}