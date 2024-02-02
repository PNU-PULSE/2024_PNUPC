#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set st;*/
using namespace std;
#define f first
#define s second
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
ll dist(pll x, pll y){
    return (y.f - x.f) * (y.f - x.f) + (y.s - x.s) * (y.s - x.s);
}
int main() {
    ll x, y, r; cin >> x >> y >> r;
    ll px, py, G; cin >> px >> py >> G;
    ll d = dist({x, y}, {px, py});
    ld length;
    if (d >= r * r){
        if (px < sqrt(d) + x - 2 * r)   length = px;
        else    length = sqrt(d) + x - 2 * r;
    }
    else{
        if (px < x - sqrt(d))   length = px;
        else    length = x - sqrt(d);
    }
    if (length <= G)    cout << "YES";
    else    cout << "NO";
    return 0;
}