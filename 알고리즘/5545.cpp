#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,a,b,c;
priority_queue<int> pq;

void input(){
    cin >> n;
    cin >> a >> b;
    cin >> c;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        pq.push(d);
    }
}

void greedy(){
    int weight = c;
    int curr = weight;
    int cnt = 0;
    int size = pq.size();
    for(int i = 0; i < size; i++){
        if(curr / (a + cnt*b) <= (curr + pq.top()) / (a + (cnt+1) * b)){
            curr += pq.top();
            pq.pop();
            cnt++;
        }
        else break;
    }
    cout << (int)(curr / (a + cnt * b));
}

void solve(){
    input();
    greedy();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();



    return 0;
}