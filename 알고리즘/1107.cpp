#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
vector<bool> v(10,false);


void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        v[x] = true;
    }
}

bool check_broken(int num){
    string s = to_string(num);
    for(int i = 0; i < s.size(); i++){
        if(v[s[i] - '0']) return false;
    }
    return true;
}

void solution(){
    int minimum = abs(n-100);
    for(int i = 0; i <= 1000000; i++) {
        if (check_broken(i)) {
            int tmp = abs(n - i) + to_string(i).size();
            minimum = min(minimum, tmp);
        }
    }
    cout << minimum;
}

void solve(){
    input();
    solution();
}

int main(){
    solve();



    return 0;
}