#include <iostream>

using namespace std;

int arr[16];
int n;
int cnt = 0;

void input(){
    cin >> n;
}

bool check(int idx){
    for(int i = 0; i < idx; i++){
        if(arr[i] == arr[idx] || abs(arr[i] - arr[idx]) == idx - i) return false;
    }
    return true;
}

void solution(int idx){
    if(idx == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        arr[idx] = i;
        if(check(idx)) solution(idx+1);
    }
}

int main(){
    input();
    solution(0);
    cout << cnt;

    return 0;
}