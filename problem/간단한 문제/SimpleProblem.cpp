#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N, p, prior = 0; cin >> N >> p;
    ll v = N / p + (N % p > 0);
    for (ll i = 1; i <= N; i++){
        ll b; cin >> b;
        if (prior > b || prior + 1 < b || b > v || i > b * p){
            cout << "NO"; return 0;
        }
        prior = b;
    }
    cout << "YES";
    return 0;
}
