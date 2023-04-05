#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string str;
vector<string> arr;
int alpha[26] = {0,};
int result = 0;

void input(){
    cin >> n;
    cin >> str;
    for(int i = 0; i < n-1; i++){
        string a;
        cin >> a;
        arr.push_back(a);
    }
}

void solution(){
    for(int i = 0; i < str.size(); i++){
        alpha[str[i]-'A'] ++;
    }
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        int tmp_alpha[26];
        int cnt = 0;
        copy(alpha,alpha+26,tmp_alpha);
        for(int j = 0; j < arr[i].size(); j++){
            if(tmp_alpha[arr[i][j] - 'A'] > 0){
                tmp_alpha[arr[i][j] - 'A']--;
                cnt++;
            }
        }
        if(str.size() == arr[i].size()) {
            if (cnt == str.size() || cnt == str.size() - 1) result++;
        }
        else if(str.size() - 1 == arr[i].size() && cnt == str.size()-1){
            result++;
        }
        else if(str.size() + 1 == arr[i].size() && cnt == str.size()){
            result++;
        }
    }
    cout << result;
}

void solve(){
    input();
    solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
