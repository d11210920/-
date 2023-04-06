#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n,t,dp[10001];
int k,s;


void dynamic(){
    for(int j = t; j >= k; j--){
        dp[j] = max(dp[j],dp[j-k] + s);
    }
}

void input(){
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> k >> s;
        dynamic();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << dp[t];
    return 0;
}