#include <bits/stdc++.h>

using namespace std;

void yes() {
    cout << "YES";
    exit(0);
}
void no() {
    cout << "NO";
    exit(0);
}

void Solve() {
    int N, p; cin >> N >> p;
    int b[N+1] {};
    for(int i=1;i<=N;i++) cin >> b[i];

    int mx = N/p + (N%p!=0);
    
    if(b[1]!=1) no();
    for(int i=2;i<=N;i++) {
        if(b[i-1]<=b[i] && b[i]<=b[i-1]+1 && b[i]<=mx) continue;
        else no();
    }
    yes();
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}

/*
잘 만듦
*/
