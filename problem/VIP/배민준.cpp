#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

using pii = pair<int,int>;

//debug
void print(vector<pii> &v) {
    for(auto [a,b] : v) {
        cout << a << " " << b << endl;
    }
    cout << endl;
}

void print(vector<int> &v) {
    for(auto i : v) cout << i << endl;
    cout << endl;
}

void print(int* a, int s, int e) {
    for(int i=s;i<=e;i++) cout << a[i] << " ";
    cout << endl;
}
const int mod = 1e9+7;

void Solve() {
    int N, M, Q; cin >> N >> M >> Q;
    int w[N+1] {};
    for(int i=1;i<=N;i++) cin >> w[i];

    vector<int> edge[N+1];
    int endpoint[N+1] {};
    int affect[N+1] {};
    set<pii> exists;
    for(int i=1;i<=M;i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);

        exists.insert({u,v});
    }

    //set the value for endpoint using v vector
    //v holds the node and sort them in the increasing order of w/
    //endpoint is the vector for determining how many VIP endpoints is that node
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);
    sort(v.begin(), v.end(), [&](int l, int r) {
        return w[l] < w[r];
    });


    for(auto cur : v) {
        for(auto next : edge[cur]) {
            if(w[next]>w[cur]) {
                endpoint[next] += endpoint[cur] + 1;
                endpoint[next] %= mod;
            }
        }
    }
    for(int i=1;i<=N;i++) {
        endpoint[i]++;
        endpoint[i] %= mod;
    }
    //initalize affect array
    sort(v.begin(), v.end(), [&](int l, int r) {
        return w[l] > w[r];
    });

    for(auto cur : v) {
        for(auto next : edge[cur]) {
            if(w[next]>w[cur]) {
                affect[cur] += affect[next] + 1;
                affect[cur] %= mod;
            }
        }
    }
    for(int i=1;i<=N;i++) {
        affect[i]++;
        affect[i] = affect[i] % mod;
    }

    int total = 0;
    for(int i=1;i<=N;i++) {
        total += endpoint[i];
        total %= mod;
    }

    while(Q--) {
        int u, v; cin >> u >> v;
        int answer = total;
        //make w[u] < w[v]
        if(w[u] > w[v]) swap(u,v);

        //if the edge exists
        if(exists.contains({u,v}) || exists.contains({v,u})) {
            int val = answer - (endpoint[u] * affect[v]) % mod;
            answer = val > 0 ? val : val+mod; 
        }
        else {
            answer += (endpoint[u] * affect[v]) % mod;
            answer %= mod;
        }
        cout << answer << endl;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
