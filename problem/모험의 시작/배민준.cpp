#include <bits/stdc++.h>

using namespace std;
void Solve() {
    int N; cin >> N;
    pair<int,int> p;
    cin >> p.first >> p.second;
    pair<int,int> a[N+1] {};
    for(int i=1;i<=N;i++) {
        cin >> a[i].first >> a[i].second;
    }
    for(int i=1;i<=N;i++) {
        if(a[i].first<=p.first && a[i].second>=p.second) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
