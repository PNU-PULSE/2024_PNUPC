#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll


int getPower(int n) {
    int ret = 1;
    for(int i=1;i<=n;i++) {
        ret *= 2;
    }
    return ret;
}

bool getResult(int val, int p) {
    if(p==2) return val%p;
    
    int a = val%p;
    if(1<=a && a<=p/2) return getResult(val, p/2);
    else return !getResult(val, p/2);
}
void Solve() {
    int N, K; cin >> N >> K;
    while(getPower(N-1)<K) {
        K -= getPower(N-1);
        N--;
    }
    cout << 1 << " ";

    if(N==1) return;
    
    vector<int> v;
    int p = 1;
    int answer = 1;
    for(int i=2;i<=N;i++) {
        p *= 2;
        int val = K % p;
        if(getResult(val, p)) answer = answer*2+1;
        else answer = answer*2;

        cout << answer << " ";
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
