#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<=b; i++) 
#define pbk push_back

using namespace std;

#define int ll
using ll = long long;
using vi = vector<int>;
struct lazySegtree {
    vi a;
    vi s;
    vi lazy;
    int n;
    lazySegtree(int n) : n(n) {
        a.resize(n + 1);
        s.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    int merge(int a, int b) {
        return a + b;
    }
    int segment(int node, int nodeLeft, int nodeRight) { // use when s, a is available and segment tree is about sum
        if (nodeLeft == nodeRight) {
            return s[node] = a[nodeLeft];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        return s[node] = merge(segment(node * 2, nodeLeft, mid), segment(node * 2 + 1, mid + 1, nodeRight));
    }
    void propagation(int node, int l, int r) {
        if (lazy[node]) {
            s[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int node, int nodeLeft, int nodeRight, int l, int r, int dif=1) { //This is for lazy propagation
        propagation(node, nodeLeft, nodeRight);
        if (nodeRight < l || r < nodeLeft) return;
        if (l <= nodeLeft && nodeRight <= r) {
            s[node] += (nodeRight - nodeLeft + 1) * dif;
            if (nodeLeft != nodeRight) {
                lazy[node * 2] += dif;
                lazy[node * 2 + 1] += dif;
            }
            return;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        update(node * 2, nodeLeft, mid, l, r, dif);
        update(node * 2 + 1, mid+1, nodeRight, l, r, dif);
        s[node] = merge(s[node * 2], s[node * 2 + 1]);
    }
    ll query(int node, int nodeLeft, int nodeRight, int l, int r) { //s should be vll
        propagation(node, nodeLeft, nodeRight);
        if (nodeRight < l || r < nodeLeft) return 0;
        if (l <= nodeLeft && nodeRight <= r) {
            return s[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        return merge(query(node * 2, nodeLeft, mid, l, r), query(node * 2 + 1, mid+1, nodeRight, l, r));
    }
    void print() {
        rep(i,1,n) {
            cout << this->query(1,1,n,i,i) << " ";
        }
        cout << endl;
    }
};

#define MAX 200001
int a[MAX] {}; //saves the sz of palindrome each side including i itself
string preprocess(const string& str) { //to find even palindrome as well
    string temp;
    for(auto c : str) {
        temp.pbk('#');
        temp.pbk(c);
    }
    temp.pbk('#');
    return temp;
}
void manacher(string& str) {
    int r = 0, p = 0; //p is the value that maximize j+A[j]
    str = preprocess(str);
    int sz = str.size();

    for (int i = 0; i < sz; i++) {
        if (i <= r) {
            a[i] = min(a[2 * p - i], r - i);
        }
        while (i-a[i]-1>=0 && i+a[i]+1<sz && str[i-a[i]-1]==str[i+a[i]+1]) {
            a[i]++;
        }
        if (r < i + a[i]) {
            r = i + a[i];
            p = i;
        }
    }
}

void Solve() {
    string str; cin >> str;
    manacher(str);
    int N = str.size()-2;
    lazySegtree lazy(N);
    rep(i,1,N) {
        int l = max(1ll, i-a[i]);
        int r = min(N, i+a[i]);
        if(a[i]!=1) lazy.update(1,1,N,i,i);
        lazy.update(1,1,N,l,r);
    }
    int Q; cin >> Q;
    while(Q--) {
        int x; cin >> x;
        x = 2*x + 1;
        cout << lazy.query(1,1,N,x,x) << endl;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
