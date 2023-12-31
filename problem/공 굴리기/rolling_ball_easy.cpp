#include <bits/stdc++.h>
using ll = long long;
ll tree[65536], subtree[65536], arr[65536];
ll solve_easy(ll n, ll k){
    for (ll i = 1 << n; i < 1 << (n + 1); i++)    tree[i] = 1;
    for (ll i = 1; i <= k; i++){
        ll pos = 1;
        while (tree[2 * pos] != 1 || tree[2 * pos + 1] != 1){
            if (subtree[2 * pos] == subtree[2 * pos + 1]) {
                if (pos % 2) pos = 2 * pos + 1;
                else pos = 2 * pos;
                subtree[pos]++;
            }
            else{
                if (subtree[2 * pos] > subtree[2 * pos + 1])    pos = 2 * pos + 1;
                else    pos = 2 * pos;
                subtree[pos]++;
            }
        }
        arr[i] = pos;
        tree[pos] = 1;
    }
    return pos;
}
void print_answer(ll value){
    if (!value)    return;
    print_answer(value / 2);
    cout << value << " ";
}
int main(){
  cin >> n >> k;
  print_answer(solve_easy(n, k));
  return 0;
}
