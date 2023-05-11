#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define ll long long
using namespace std;

struct planet{
    ll x;
    ll y;
    ll z;
};

int ans = 0;
vector<planet> v;
vector<pair<ll,pair<int,int>>> edge;
int n;
int cnt = 1;
int parent[100001];
vector<pair<int,int>> X;
vector<pair<int,int>> Y;
vector<pair<int,int>> Z;

void input(){
    cin >> n;
    v.push_back({0,0,0});
    for(int i = 1; i <= n; i++){
        ll a,b,c;
        parent[i] = i;
        cin >> a >> b >> c;
        X.push_back({a,i});
        Y.push_back({b,i});
        Z.push_back({c,i});

    }
}

int getParent(int x){
    if(x == parent[x])return x;
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
}

void solve(){
    input();
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(Z.begin(),Z.end());

    for(int i = 1; i < n; i++){
        edge.push_back({abs(X[i].first - X[i-1].first),{X[i].second,X[i-1].second}});
        edge.push_back({abs(Y[i].first - Y[i-1].first),{Y[i].second,Y[i-1].second}});
        edge.push_back({abs(Z[i].first - Z[i-1].first),{Z[i].second,Z[i-1].second}});
    }
    sort(edge.begin(),edge.end());

    for(int i = 0; i < edge.size(); i++){
        if(cnt == n) break;

        int first = edge[i].second.first;
        int second = edge[i].second.second;
        int dist = edge[i].first;
        if(!findParent(first,second)){
            unionParent(first,second);
            cnt++;
            ans += dist;
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