#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
ll weight(ll l, ll r){
    return l > r;
}
ll f(ll l, ll r, ll k){
    if (l == r)  return l;
    ll m = (l + r) >> 1, nk = (k + 1) >> 1;
    if (k % 2)  return f(l, m + weight(l, r), nk);
    return f(r, m + weight(r, l), nk);
}
ll solve(){
    cin >> n >> k;
    for (ll i = n - 1; i >= 0; i--){
        if ((1 << i) >= k){
            return f((1 << (i + 1)) - 1, 1 << i, k);
        }
        k -= 1 << i;
    }
}
void print_answer(ll value){
    if (!value)    return;
    print_answer(value / 2);
    cout << value << " ";
}
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    print_answer(solve());
    return 0;
}
