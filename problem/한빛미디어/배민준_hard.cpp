#include <bits/stdc++.h>

using namespace std;

void Solve() {
    int Q; cin >> Q;
    multiset<int> ms;
    while(Q--) {
        int op, p; cin >> op;
        if(op==1) {
            cin >> p;
            ms.insert(p);
        }
        else if(op==2) {
            cin >> p;
            ms.erase(p);
        }
        else {
            int answer=0;
            int bp = 0;
            for(auto p : ms) {
                if(2*bp<=p) {
                    bp = p;
                    answer++;
                }
            }
            answer++;
            cout << answer << endl;
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
