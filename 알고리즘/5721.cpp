#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;


int m, n;
int sum[100001];
int dp[100001];

void dynamic(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            int cnt;
            cin >> cnt;

            if (j == 1){
                dp[j] = cnt;
            }
            else if(j == 2){
                dp[j] = max(dp[j-1],cnt);
            }
            else {
                dp[j] = max(dp[j - 1], cnt + dp[j - 2]);
            }
        }
        sum[i] = dp[n];
    }
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= m; i++){
        int cnt = sum[i];
        if(i == 1)dp[i] = cnt;
        else if(i == 2) dp[i] = max(dp[i-1],cnt);
        else{
            dp[i] = max(dp[i-1],cnt + dp[i-2]);
        }
    }
}

void solve(){
    while (true){
        cin >> m >> n;
        if (m==0 && n==0)break;
        dynamic();
        cout << dp[m] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}