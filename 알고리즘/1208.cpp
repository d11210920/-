#include <iostream>
#include <map>

using namespace std;

int n,s;
int arr[41];
map<int,int> subsum;
long long cnt = 0;

void input(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void leftSum(int left,int sum){
    if(left == n/2){
        subsum[sum]++;
        return;
    }
    leftSum(left + 1, sum+arr[left]);
    leftSum(left + 1, sum);
}

void rightSum(int mid, int sum){
    if(mid == n){
        cnt += subsum[s-sum];
        return;
    }
    rightSum(mid+1,sum+arr[mid]);
    rightSum(mid+1,sum);
}

void solution(){
    input();
    leftSum(0,0);
    rightSum(n/2,0);
    if(s == 0) {
        cout << cnt - 1;
    }
    else cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();
    return 0;
}