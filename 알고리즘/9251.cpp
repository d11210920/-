#include <iostream>
#include <algorithm>
#include <string>
#define MAX 987654321

using namespace std;

string str1, str2;

int dp[1001][1001];


void input(){
    cin >> str1 >> str2;
    for(int i = 0; i < str1.size(); i++){
        for(int j = 0; j < str2.size(); j++){
            dp[i][j] = 0;
        }
    }
}

void solution(){
    dp[0][0] = 0;
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[str1.size()][str2.size()];
}

void solve(){
    input();
    solution();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}