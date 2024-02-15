#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll p, S; string N;
    cin >> p >> S;
    cin >> N;
    ll v = 1;
    ll m = 0;
    for (auto it = rbegin(N); it != rend(N); it++){
        m = (m + (*it - '0') * v) % p;
        v = (v * 10) % p;
    }
    if (m > 0)  cout << 0;
    else    cout << 1;
    return 0;
}
