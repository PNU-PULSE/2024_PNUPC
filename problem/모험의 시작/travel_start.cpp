#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N, P, S; cin >> N >> P >> S;
    ll atk = -1;
    while (N--){
        ll c, p; cin >> c >> p;
        if (P >= c) atk = max(atk, p);
    }
    if (atk > S)    cout << 1;
    else    cout << 0;

    return 0;
}