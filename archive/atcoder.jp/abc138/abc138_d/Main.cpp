#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

using Graph = vector< pair<int, vector<int> > >;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, Q;
    cin >> N >> Q;
    Graph tree(N);
    for(int i = 0; i < N - 1; ++i){
        int a, b; cin >> a >> b;
        --a, --b;
        tree[b].second.push_back(a);
    }

    for(int i = 0; i < Q; ++i){
        int p, x; cin >> p >> x;
        --p;
        tree[p].first += x;
    }

    for(int i = 0; i < N; ++i){
        for(auto it : tree[i].second){
            tree[i].first += tree[it].first;
        }
        cout << tree[i].first << endl;
    }

    return 0;
}
