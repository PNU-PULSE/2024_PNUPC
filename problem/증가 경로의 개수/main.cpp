#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll mod = 1e9 + 7;
vector<ll> vec[100010];
ll wi[100010];
ll dp1[100010], dp2[100010];
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N, M, Q; cin >> N >> M >> Q;
    fill_n(dp1, 100005, 1); fill_n(dp2, 100005, 1);
    vector<pll> arr(N, {0, 0});
    ll base1 = 0, base2 = 0;
    for (ll i = 0; i < N; i++){
        cin >> wi[i]; arr[i] = {wi[i], i};
    }
    for (ll i = 0; i < M; i++){
        ll u, v; cin >> u >> v; u--; v--;
        vec[u].emplace_back(v); vec[v].emplace_back(u);
    }
    sort(begin(arr), end(arr));
    for (auto [w, i]: arr){
        for (ll nxt: vec[i]){
            if (wi[nxt] > w)    dp1[nxt] = (dp1[nxt] + dp1[i]) % mod;
        }
        base1 = (base1 + dp1[i]) % mod;
    }
    for (auto it = rbegin(arr); it != rend(arr); it++){
        auto [w, i] = *it;
        for (ll nxt: vec[i]){
            if (wi[nxt] < w)    dp2[nxt] = (dp2[nxt] + dp2[i]) % mod;
        }
        base2 = (base2 + dp2[i]) % mod;
    }
    while (Q--){
        ll u, v; cin >> u >> v; u--; v--;
        if (wi[u] == wi[v]){
            cout << base1 << "\n";
        }
        else {
            if (wi[u] > wi[v]) swap(u, v);
            ll op = (mod + base1 - (dp1[u] * dp2[v]) % mod) % mod;
            cout << op << "\n";
        }
    }

    return 0;
}